import React, { useState } from "react";
import { useEffect } from "react";
import "./RegisterForm.css";
import { FaUser, FaLock, FaEnvelope } from "react-icons/fa";
import { Link } from "react-router-dom";
import axios from "axios";

const RegisterForm = () => {
    useEffect(() => {
        // Add a class to the body when the login form is displayed
        document.body.classList.add("register-background");

        // Cleanup the class when the component is unmounted
        return () => {
            document.body.classList.remove("register-background");
        };
    }, []);
    const [username, setUsername] = useState("");
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");
    const [errorMessage, setErrorMessage] = useState("");
    const [successMessage, setSuccessMessage] = useState("");

    const handleSubmit = async (e) => {
        e.preventDefault();

        try {
            const response = await axios.post("http://localhost:5000/register", {
                username,
                email,
                password,
            });

            if (response.status === 201) {
                setSuccessMessage("Registration successful! You can now log in.");
                setErrorMessage("");
                setUsername("");
                setEmail("");
                setPassword("");
            }
        } catch (error) {
            if (error.response && error.response.status === 409) {
                setErrorMessage("Username or email already exists.");
            } else {
                setErrorMessage("An error occurred. Please try again.");
            }
            setSuccessMessage("");
        }
    };

    return (
        <div className="wrapper">
            <form onSubmit={handleSubmit}>
                <h1>Register</h1>

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
                        type="email"
                        placeholder="Email"
                        value={email}
                        onChange={(e) => setEmail(e.target.value)}
                        required
                    />
                    <FaEnvelope className="icon" />
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
                {successMessage && <p className="success">{successMessage}</p>}

                <button type="submit">Register</button>

                <div className="register-link">
                    <p>Already have an account?</p>
                    <Link to="/login">Login</Link> {/* Link back to Login */}
                </div>
            </form>
        </div>
    );
};

export default RegisterForm;
