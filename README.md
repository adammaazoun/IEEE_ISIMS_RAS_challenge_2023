# IEEE_RAS_challenge_2023
# Safety Matrix - V2V Project

A Vehicle-to-Vehicle (V2V) safety project utilizing YOLO v5 model and a mobile app.


## Introduction

Safety matrix is a next-generation road safety solution powered by Vehicle-to-Vehicle (V2V) technology. It actively prevents collisions by enabling real-time communication between vehicles, providing predictive warnings, and facilitating autonomous collision avoidance. Safety Matrix: ensures safer roads, reduced collision rates, and improved traffic flow through dynamic coordination and adaptive lane management.

## Features

n our commitment to enhancing car safety, The idea, centered on:
- safety
-accident avoidance
-efficiency
-proactive decision-making
not only reinforce individual vehicle autonomy but also foster a collaborative and intelligent vehicular ecosystem.




### Installation and running ai model

1. Clone the repository:

    ```bash
    git clone https://github.com/ultralytics/yolov5
    ```

2. Install dependencies:

    ```bash
    pip install -r requirements.txt
    ```
3.run model:
    ```bash
    python detect3.py --weights last.pt --source "photo_adress"
    ```
    ```bash
    python detect3.py --weights last.pt --source 0(for real time detection)
    ```
    

## radio communication prototype
both cars use the same circuit ,
![alt text]([https://github.com/adammaazoun/IEEE_ISIMS_RAS_challenge_2023/blob/f34905511aab673d295cb10b267ee38336b1e3d1/circuit.png])
reciver car gets the ras_res1.ino code 
and the transmitter car get the ras_trans1.ino code


