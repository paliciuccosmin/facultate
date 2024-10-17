import React from "react";
import { Navigate } from "react-router-dom";

// PrivateRoute component to protect specific routes
const PrivateRoute = ({ children }) => {
    const isAuthenticated = localStorage.getItem("isAuthenticated");

    return isAuthenticated ? children : <Navigate to="/login" />;
};

export default PrivateRoute;
