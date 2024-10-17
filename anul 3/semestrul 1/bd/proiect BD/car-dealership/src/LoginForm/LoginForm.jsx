import React, { useState } from "react";
import { useEffect } from "react";
import "./LoginForm.css";
import { FaUser, FaLock } from "react-icons/fa";
import { Link, useNavigate} from "react-router-dom"; // Import Link from react-router-dom
import axios from "axios";



const LoginForm = () => {

    useEffect(() => {
        // Add a class to the body when the login form is displayed
        document.body.classList.add("login-background");
        document.body.classList.add(".wrapper");
        // Cleanup the class when the component is unmounted
        return () => {
            document.body.classList.remove(".wrapper");
            document.body.classList.remove("login-background");
        };
    }, []);
    
    const [username, setUsername] = useState("");
    const [password, setPassword] = useState("");
    const [errorMessage, setErrorMessage] = useState("");
    const navigate = useNavigate();
    const handleSubmit = async (e) => {
        e.preventDefault();

        try {
            const response = await axios.post("http://localhost:5000/login", {
                username,
                password,
            });

            if (response.status === 200) {
                localStorage.setItem("isAuthenticated", "true");
                navigate("/home");
            }
        } catch (error) {
            if (error.response && error.response.status === 404) {
                setErrorMessage("User not found");
            } else if (error.response && error.response.status === 401) {
                setErrorMessage("Invalid credentials");
            } else {
                setErrorMessage("An error occurred. Please try again.");
            }
        }
    };

    return (
        
        <div className="wrapper">
            <form onSubmit={handleSubmit}>
                <h1>Login</h1>
                <div className="input-box">
                    <input
                        type="text"
                        placeholder="Username"
                        value={username}
                        onChange={(e) => setUsername(e.target.value)}
                        required
                    />
                    <FaUser className="icon" />
                </div>
                <div className="input-box">
                    <input
                        type="password"
                        placeholder="Password"
                        value={password}
                        onChange={(e) => setPassword(e.target.value)}
                        required
                    />
                    <FaLock className="icon" />
                </div>
                {errorMessage && <p className="error">{errorMessage}</p>}
                <div className="remember-forgot">
                    <label>
                        <input type="checkbox" /> Remember Me
                    </label>
                    <a href="#">Forgot Password</a>
                </div>
                <button type="submit">Login</button>
                <div className="register-link">
                    <p>Don't have an account?</p>
                    <Link to="/register">Register</Link> {/* Use Link to navigate */}
                </div>
            </form>
        </div>
    );
    
};


export default LoginForm;
