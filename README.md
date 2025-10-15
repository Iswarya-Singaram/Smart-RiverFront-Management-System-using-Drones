# Smart-RiverFront-Management-System-using-Drones
Design File Drive Link:
https://drive.google.com/drive/folders/1U8e2riaNZgKBY7UARJg0z6c4vCxNJoVI?usp=sharing

# 🌊 Smart Autonomous Riverfront Management System  
### An Innovative Solution for the Smart Management of the Sabarmati Riverfront  

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
![Python](https://img.shields.io/badge/Python-3.x-blue.svg)
![Flask](https://img.shields.io/badge/Backend-Flask-lightblue.svg)
![Arduino](https://img.shields.io/badge/IoT-Arduino-orange.svg)
![Status](https://img.shields.io/badge/Status-Active-success.svg)

---

## 🏞️ Overview  

The **Smart Autonomous Riverfront Management System** is a comprehensive, technology-driven solution designed for the **smart management of the Sabarmati Riverfront** and other urban water bodies.  
It integrates **IoT**, **AI**, **Drones**, and **Citizen Participation** into a unified platform that ensures a **sustainable, clean, and safe aquatic ecosystem**.  

This project aims to provide a **cost-effective**, **scalable**, and **replicable** model for smart river management across India.

---

## 🎯 Project Vision & Alignment  

This solution directly addresses the key challenges of **urban water body management** by providing an innovative and scalable platform aligned with sustainable development goals.  

### ✅ Expected Outcomes
- IoT & Sensor-Based Water Quality Monitoring  
- Smart Waste Detection & Removal  
- Flood Prediction & Water Level Management  
- Citizen Engagement Platforms  
- Safety & Surveillance Solutions  
- Biodiversity Monitoring Tools  

---

## ✨ Core Features  

### 1. IoT & Sensor-Based Water Quality Monitoring  
A live dashboard provides real-time data and predictive analytics using low-cost IoT sensors.  

- **Real-Time Data Collection:** Continuously monitors Temperature, pH, TDS, Turbidity, BOD, and COD.  
- **Predictive Analytics & Insights:** Generates alerts (“Warning,” “Danger”) and actionable insights to prevent pollution events.

   <img width="1600" height="899" alt="image" src="https://github.com/user-attachments/assets/68089dc5-0d4a-45d2-8c5a-3272b70ece23" />


---

### 2. Safety, Surveillance & Smart Detection  
Autonomous drones and centralized alert systems ensure safety and environmental security.  

- **Autonomous Drone Missions:** Perform aerial surveillance and detect floating waste via AI/ML models.  
- **Emergency Alert System:** Broadcast critical alerts such as distress signals, drowning detection, and flood warnings.

   <img width="1600" height="899" alt="image" src="https://github.com/user-attachments/assets/3b6fe99f-c19e-44d1-87c2-c64bb14ddd6c" />


---

### 3. Biodiversity Monitoring & Aquatic Life Sustainability  
An AI-driven ecological module assesses aquatic biodiversity health.  

- **Health & Survival Analysis:** Evaluates the impact of water quality on local fish species (Rohu, Catla, Tilapia).  
- **Environmental Indicators:** Helps maintain a balanced and healthy aquatic ecosystem.

  <img width="1600" height="899" alt="image" src="https://github.com/user-attachments/assets/e533fe7c-6e1c-42ee-9685-eefb72a3dd9d" />


---

### 4. Citizen Engagement Platform  
Empowers citizens to actively participate in river management and conservation.  

- **Issue Reporting:** Citizens can report illegal dumping or pollution incidents with photos and geotags.  
- **Volunteer & Awareness:** Connects people with cleanup drives and awareness initiatives.  
<img width="1600" height="899" alt="image" src="https://github.com/user-attachments/assets/80386407-dd61-4dd2-9550-867d4b085a1d" />

---

### 5. Flood Prediction & Water Level Management  
Integrates with AI-based forecasting models for real-time flood prediction and response.  

- **Integrated Alerts:** Uses river level, weather, and hydrological data to issue early warnings and support disaster preparedness.  
<img width="1600" height="899" alt="image" src="https://github.com/user-attachments/assets/cc1d2e6f-5b4f-4274-9987-939521ca31f3" />


---

## ⚙️ System Architecture 

### 🧩 Technology Stack  

| Layer | Technologies Used |
|-------|--------------------|
| **Frontend** | HTML, CSS, JavaScript |
| **Backend** | Python (Flask Framework) |
| **IoT Hardware** | ESP32 / ESP8266, Sensors, Drones |
| **IoT Code** | C / C++ (Arduino Framework) |
| **Database (optional)** | SQLite / Firebase / MongoDB |

---

## 🌐 Scalability & Impact  

- 💸 **Cost-Effective:** Utilizes affordable, open-source hardware (ESP boards and sensors).  
- 🔁 **Scalable:** Modular architecture allows easy integration of new modules or sensors.  
- 🌱 **Sustainable:** Enables proactive intervention through continuous environmental monitoring.  
- 🇮🇳 **Replicable:** Can be deployed in other Indian cities for standardized smart water management.  

---

## 🚀 Getting Started  

Follow these steps to set up the system locally.  

### 🧰 Prerequisites  

- Python 3.x  
- Arduino IDE  
- ESP32 or ESP8266 development board with water quality sensors  

---

### 🖥️ Backend Setup  

```bash
# Clone the repository
git clone https://github.com/your-username/riverfront-management.git
cd riverfront-management

# Create and activate a virtual environment
python -m venv venv
source venv/bin/activate   # On Windows: venv\Scripts\activate

# Install dependencies
pip install -r requirements.txt

# Run the Flask application
flask run
 const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* serverName = "http://YOUR_BACKEND_IP:5000/update";




