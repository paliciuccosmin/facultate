const handleLoginSuccess = () => {
    localStorage.setItem("isAuthenticated", "true");
    navigate("/home");
};