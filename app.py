from flask import Flask, request, jsonify, render_template
import threading
import time
import random

# Initialize the Flask app
app = Flask(__name__, template_folder='templates')

# --- In-Memory Data Store ---
latest_data = {
    'temperature': 29.5, 'tds': 750, 'turbidity': 15.2, 'ph': 5.8,
    'cod': 55, 'bod': 12, 'timestamp': time.time()
}
data_lock = threading.Lock()

# --- Background Thread for Data Simulation ---
def simulate_data_change():
    global latest_data
    while True:
        with data_lock:
            latest_data['temperature'] += random.uniform(-0.1, 0.1)
            latest_data['ph'] += random.uniform(-0.05, 0.05)
            latest_data['tds'] += random.uniform(-2, 2)
            latest_data['turbidity'] += random.uniform(-0.2, 0.2)
            latest_data['bod'] += random.uniform(-0.3, 0.3)
            latest_data['cod'] += random.uniform(-1, 1)

            if latest_data['ph'] > 14: latest_data['ph'] = 14
            if latest_data['ph'] < 0: latest_data['ph'] = 0
            if latest_data['temperature'] < 0: latest_data['temperature'] = 0
            if latest_data['tds'] < 0: latest_data['tds'] = 0
            
            latest_data['timestamp'] = time.time()
        
        time.sleep(2)

# --- Flask Routes for Each Page ---

@app.route('/')
def home():
    return render_template('home.html')

@app.route('/water_quality')
def water_quality():
    return render_template('water_quality.html')

# UPDATED ROUTE
@app.route('/drone_mission')
def drone_mission():
    """Serves the combined drone mission planning page."""
    return render_template('drone_mission.html')

@app.route('/aquatic_life')
def aquatic_life():
    return render_template('aquatic_life.html')

@app.route('/alerts')
def alerts():
    return render_template('alerts.html')

@app.route('/citizen_engagement')
def citizen_engagement():
    return render_template('citizen_engagement.html')

# --- API Endpoints ---

@app.route('/get_data', methods=['GET'])
def get_data():
    with data_lock:
        response_data = latest_data.copy()
    return jsonify(response_data)

# --- Main Entry Point ---

if __name__ == '__main__':
    simulation_thread = threading.Thread(target=simulate_data_change)
    simulation_thread.daemon = True
    simulation_thread.start()
    
    print("--- Smart River Management Dashboard Server ---")
    print("--- Live Data Simulation is ACTIVE ---")
    print("Starting server...")
    print("Open your web browser and navigate to http://127.0.0.1:5000")
    app.run(host='0.0.0.0', port=5000, debug=False)