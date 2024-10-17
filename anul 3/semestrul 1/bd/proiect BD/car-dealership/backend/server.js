const express = require("express");
const bcrypt = require("bcryptjs");
const sql = require("mssql/msnodesqlv8");
const cors = require("cors");
const app = express();
app.use(express.json()); // Parse incoming JSON requests
app.use(cors()); // Allow cross-origin requests

// SQL Server connection configuration
const dbConfig = {
    server: "DESKTOP-4N2DR68\\SQLEXPRESS", // Your server/instance name
    database: "CarDealershipDB",  // Your database name
    driver: "msnodesqlv8",  // Using msnodesqlv8 for Windows authentication
    options: {
        trustedConnection: true,  // Use this option for Windows Authentication
        encrypt: false,  // Set this to false for local development
        trustServerCertificate: true,  // If using a self-signed certificate
    },
};

// Connect to the database
sql.connect(dbConfig)
    .then(() => console.log("Connected to SQL Server"))
    .catch((err) => console.error("SQL Server connection error", err));

// Registration endpoint
app.post("/register", async (req, res) => {
    const { username, email, password } = req.body;

    try {
        // Check if username or email already exists
        const checkUser = await sql.query`SELECT * FROM Users WHERE Username = ${username} OR Email = ${email}`;
        if (checkUser.recordset.length > 0) {
            return res.status(409).json({ message: "Username or email already exists" });
        }

        // Hash the password
        const hashedPassword = await bcrypt.hash(password, 10);

        // Insert the new user into the database
        await sql.query`INSERT INTO Users (Username,Email, Password) VALUES (${username}, ${email}, ${hashedPassword})`;

        res.status(201).json({ message: "User registered successfully!" });
    } catch (error) {
        console.error("Error during registration:", error);
        res.status(500).json({ message: "Internal server error" });
    }
});

// Login endpoint
app.use(express.json()); // Ensure you're using this to parse JSON

app.post("/login", async (req, res) => {
    const { username, password } = req.body;

    if (!username || !password) {
        return res.status(400).json({ message: "Username and password are required" });
    }

    try {
        // Fetch the user from the database
        const result = await sql.query`SELECT * FROM Users WHERE Username = ${username}`;
        const user = result.recordset[0];
        console.log(user.Password);
        if (!user) {
            return res.status(404).json({ message: "User not found" });
        }

        // Check if user.password exists
        if (!user.Password) {
            return res.status(500).json({ message: "Password not set for this user" });
        }

        // Compare provided password with the hashed password from DB
        const isPasswordValid = await bcrypt.compare(password, user.Password);

        if (!isPasswordValid) {
            return res.status(401).json({ message: "Invalid credentials" });
        }

        res.status(200).json({ message: "Login successful" });
    } catch (error) {
        console.error("Error during login:", error);
        res.status(500).json({ message: "Internal server error" });
    }
});

const PORT = 5000;
app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
