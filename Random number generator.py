# -*- coding: utf-8 -*-
"""
Created on Tue Mar 30 14:46:56 2021

@author: sibo0
"""
from random import seed
from random import randint, shuffle
import time
from tkinter import *
import numpy as np
from random import randint, shuffle
import matplotlib.pyplot as plt
from matplotlib.artist import Artist
import pandas as pd

# Random number generter: 1. position num 2. group of motions


def RNG(values, groups):
    positions = []
    for _ in range(groups):
        shuffle(values)
        positions.extend(values)

    i = 1
    for i in range(len(positions)):
        if positions[i] == positions[i-1] and i < len(positions)-1:
            positions[i], positions[i+1] = positions[i+1], positions[i]
    return positions


def clicked():
    global number
    global displayLabel
    displayLabel.config(text=positions[number])
    if number <= 120:
        number += 1
    else:
        displayLabel.config(text='END')


# Main function
if __name__ == "__main__":
    values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    positions = RNG(values, 10)
    # positions = pd.DataFrame(positions)
    # path = "C:/Users/sibo0/OneDrive - Nanyang Technological University (1)/HRI software/reaching and placing task/src/d01_data/01_raw"
    # positions.to_csv(path + "positions5.csv")

root = Tk()
root.geometry("1000x1000")
root.title("RNG")
root.grid()

number = 0
# displayVariable = StringVar()
# for number in range(len(positions)):
displayLabel = Label(
    root, text=positions[number], fg='Red', font=("Helvetica", 300))
displayLabel.grid(column=1, row=1)
button = Button(root, text="Push Me", command=clicked,
                width=20, font=("Helvetica", 80), bg='Blue')
button.grid(column=1, row=2)


root.mainloop()
#%% save postion data to 
positions = pd.DataFrame(positions)
path = "C:/Users/sibo0/OneDrive - Nanyang Technological University (1)/HRI software/reaching and placing task/src/d01_data/01_raw/"
positions.to_csv(path + "positions_xin2.csv",index=False, index_label=False,header=False)
