# Remote Health Monitoring System Simulation

## Project Overview

For my Object-Oriented Programming project, I have designed and simulated a comprehensive remote health monitoring system. This system aims to support patients with limited mobility by allowing them to consult remotely with their health providers. Additionally, health providers can remotely collect vital signs and other health information from patients through wearable Internet of Things (IoT) devices.

### Major Components

#### IoT Sensors

Patients wear various IoT devices to measure vitals such as oxygen saturation, pulse, BMI, blood pressure, specific movement sensors, and general movement sensors. These devices record data and detect falls or prompt position changes when necessary.

#### Remote Monitoring Control Center (RMC2)

Wearable devices send periodic updates to the patient's mobile app, which compiles daily updates and sends encrypted data to the RMC2 over the Internet. The RMC2 indexes and stores data in cloud storage. Health providers can authenticate themselves to the RMC2, request specific patient data, and view it if authorized by the patient.

#### Electronic Health Records (EHRs)

The RMC2 maintains Electronic Health Records (EHRs) for each patient. These records include consultation history, prescriptions, recommendations, demographic data, dietary restrictions, allergies, medications, and chronic health conditions. EHRs are stored encrypted in the cloud and can be updated by health providers.

#### Patients' Mobile App

The app allows patients to schedule remote consultations, make and receive calls with doctors, view and search through past health data, see stats and summaries, view prescriptions and recommendations, and manage security features. Patients can encrypt and decrypt their data, set access control for health providers, and approve or deny access requests.

#### Health Provider Application

Health providers can log in, view and approve/reject appointment requests, access patients' consultation history, search for specific patient data, request additional data, add data to a patient's medical record, and edit EHRs if authorized.

### Data and File Handling

The program includes sample data for 10 patients, at least 5 doctors, and historical data for each patient. Binary file handling is implemented for reading/writing these files, ensuring that all data is stored and retrieved from files.

### Design

The project begins with a class diagram and CRC modeling to identify classes, responsibilities, and collaborators. The design incorporates concepts such as composition, aggregation, association, and inheritance to demonstrate a strong understanding of object-oriented design principles.

### Open-ended Problems

Details such as encryption, access control, menu design, program flow, communication simulation, data analysis, statistics calculation, and graph rendering are left open-ended. The implementation showcases file handling, operator overloading, polymorphism, virtual functions, and other concepts taught in the course.
