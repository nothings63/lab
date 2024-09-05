from flask import Flask, request, send_from_directory
import subprocess
import os
import requests,time
from bs4 import BeautifulSoup
from zapv2 import ZAPv2

app = Flask(__name__)

ZAP_API_KEY = '3dp5bf7bm41io13cdu36df3cvb'  # Replace with your actual ZAP API key
ZAP_URL = 'http://localhost:8080'  # Default ZAP API address

zap = ZAPv2(apikey=ZAP_API_KEY, proxies={'http': ZAP_URL, 'https': ZAP_URL})
def scan_vulnerabilities(url):
    """Scans a website for vulnerabilities using OWASP ZAP."""
    try:
        # Start a new ZAP session
        print("Starting new ZAP session...")
        zap.core.new_session(name='mysession', overwrite=True)

        # Open the target URL in ZAP
        print(f"Accessing target {url} in ZAP...")
        zap.urlopen(url)
        time.sleep(2)  # Allow ZAP time to access the URL

        # Start the active scan
        print(f"Starting active scan on {url}...")
        scan_id = zap.ascan.scan(url)
        while int(zap.ascan.status(scan_id)) < 100:
            print(f"Scan progress: {zap.ascan.status(scan_id)}%")
            time.sleep(5)  # Wait 5 seconds between checks

        print("Scan completed.")
        
        # Retrieve the results
        alerts = zap.core.alerts(baseurl=url)
        if alerts:
            results = "\n".join([f"Risk: {alert['risk']} - {alert['alert']}" for alert in alerts])
            print(f"Alerts found: {len(alerts)}")
            return results
        else:
            print("No vulnerabilities found.")
            return "No vulnerabilities found."

    except Exception as e:
        print(f"Error during scan: {str(e)}")
        return f"Error during scan: {str(e)}"


def scan_malware(url):
    """Mock function to simulate scanning a website for malware."""
    try:
        response = requests.get(url)
        if response.status_code == 200:
            return "No malware found (mock result)"
        else:
            return "Failed to fetch website content"
    except Exception as e:
        return f"Error fetching website: {str(e)}"

@app.route('/')
def index():
    return send_from_directory('static', 'index.html')

@app.route('/scan', methods=['POST'])
def scan():
    url = request.form['url']
    scan_type = request.form['scan_type']

    if scan_type == 'vulnerability':
        scan_result = scan_vulnerabilities(url)
    elif scan_type == 'malware':
        scan_result = scan_malware(url)
    else:
        scan_result = "Invalid scan type selected."

    return f"<h1>Scan Results for {url}</h1><pre>{scan_result}</pre>"

if __name__ == '__main__':
    app.run(debug=True)
