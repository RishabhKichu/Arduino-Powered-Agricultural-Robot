# 🌱 AgriBot – Arduino-Powered Agricultural Robot

A low-cost, multi-functional field robot designed for basic agricultural tasks like seed dispensing, soil moisture monitoring, and water delivery. Built using Arduino, servo control, moisture sensors, and a custom mechanical rig on a 4-wheel platform.

> 🧪 This project was built and programmed for a **school science exhibition**, where it was successfully demonstrated live.

---

## 🔧 Key Features

- **Custom wooden wheels** attached to a plastic wheels that came with the chasis to increase ground clearance to impliment the soil moisture system
- **4-wheel drive** powered by a dual motor driver, capable of forward, reverse, and turning  
- **Servo-controlled seed dispenser** using a cut plastic bottle for seed delivery  
- **Mini water pump system** with a plastic reservoir for demonstration purposes
- **Moisture sensor** mounted on a vertical rack-and-pinion system to measure soil moisture on the go  
- **Humidity sensor + LCD display** showing live environmental readings for demonstrative purposes
- **LiPo battery powered** for field mobility and extended runtime

---

## 🔍 Components Used

| Component | Purpose |
|----------|---------|
| Arduino UNO | Main controller |
| L298N Motor Driver | Motor control |
| SG90 Servo Motor | Seed dispenser rotation |
| Submersible Pump | Water delivery |
| DHT11 Sensor | Humidity measurement |
| Capacitive Soil Moisture Sensor | Soil condition detection |
| Rack-and-Pinion Mechanism | Depth-based soil probing |
| 16x2 LCD | Real-time data display |
| LiPo Battery | Portable power source |

---

## 🧠 Problems I Faced

- **Rack and Pinion Mounting Without 3D-Printed Parts**  
  Designing the vertical rack-and-pinion system was challenging due to the lack of custom 3D-printed brackets. I resolved this by using carefully placed wedges to guide the gear rack through pre-drilled holes in the chassis, ensuring proper alignment and smooth movement.

- **Seed Dispensing System Friction Issues**  
  The seed dispensing screw mechanism required multiple iterations. High friction between the screw and the cardboard slots led to jamming due to low torque of the servo motor. I had to adjust the width of the slot through trial and error to achieve consistent motion.


---

## 🎯 Purpose & Limitations

This project was built as a **conceptual prototype** for a science exhibition, aimed at demonstrating low-cost automation in agriculture. It served to:

- Showcase modular design of an agri-robot
- Learn mechanical control, sensing, and integration
- Test mechanisms like seed dispensing and moisture detection

⚠️ **Limitations**:
- The water tank is small and intended only for demo cycles
- Plastic+wood construction isn't suitable for rugged outdoor use
- Power and component selection was optimized for portability, not durability

---

## 📸 Preview

![AgriBot](./Images/agrobot.jpg)

---

