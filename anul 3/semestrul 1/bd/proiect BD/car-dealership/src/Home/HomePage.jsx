import React, { useEffect, useState } from "react";
import "./HomePage.css";
import { useNavigate } from "react-router-dom";

const Home = () => {
    const [carCount, setCarCount] = useState(0); // Holds total number of cars
    const [cars, setCars] = useState([]); // Holds the list of cars
    const [sales, setSales] = useState(0); // Holds the sales summary
    const navigate = useNavigate();

    useEffect(() => {
        // Ensure no background image is applied when home is shown
        document.body.classList.add("home-background");
        document.body.classList.add(".home-container");
        // Fetch dashboard data (car count, sales, available cars) from backend API
        fetchDashboardData();

        // Cleanup when component is unmounted
        return () => {
            document.body.classList.remove(".home-container");
            document.body.classList.remove("home-background");
        };
    }, []);

    const fetchDashboardData = async () => {
        try {
            // Simulate fetching data from API
            // Replace the following hardcoded values with actual API calls
            const carsData = [
                { id: 1, model: "Toyota Corolla", year: 2018, price: 15000 },
                { id: 2, model: "Honda Civic", year: 2020, price: 20000 },
                { id: 3, model: "Ford Focus", year: 2017, price: 12000 },
            ];

            setCars(carsData);
            setCarCount(carsData.length);
            setSales(250000); // Example sales number (replace with actual API data)
        } catch (error) {
            console.error("Failed to fetch dashboard data", error);
        }
    };

    // Logout handler
    const handleLogout = () => {
        localStorage.removeItem("isAuthenticated");
        navigate("/login");
    };

    return (
        <div className="home-container">
            <header className="home-header">
                <h1>Welcome to the Car Dealership Dashboard</h1>
                <button className="logout-btn" onClick={handleLogout}>
                    Logout
                </button>
            </header>

            <section className="home-dashboard">
                <h2>Dashboard</h2>
                <div className="dashboard-summary">
                    <div className="summary-item">
                        <h3>Total Cars</h3>
                        <p>{carCount}</p>
                    </div>
                    <div className="summary-item">
                        <h3>Total Sales</h3>
                        <p>${sales.toLocaleString()}</p>
                    </div>
                </div>
            </section>

            <section className="home-car-listings">
                <h2>Available Cars</h2>
                <div className="car-list">
                    {cars.length > 0 ? (
                        cars.map((car) => (
                            <div key={car.id} className="car-item">
                                <h3>{car.model} ({car.year})</h3>
                                <p>Price: ${car.price.toLocaleString()}</p>
                            </div>
                        ))
                    ) : (
                        <p>No cars available at the moment.</p>
                    )}
                </div>
            </section>
        </div>
    );
};

export default Home;
