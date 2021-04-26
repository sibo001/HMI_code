# -*- coding: utf-8 -*-
"""
Created on Mon Apr 19 13:23:14 2021

@author: sibo0
"""
import numpy as np
from random import randint

class coordinate_gen:
    def __init__(self, radius, x_center, y_center, size):
        self.radius = radius  # Normal person's working radius
        self.Xc = x_center
        self.Yc = y_center    # Home localization
        self.size = size      # numbers of coordinates
    def randpoint(self, norm_r):
        cords_set = []
        phi = np.random.random(size=self.size) * np.pi
        r = np.sqrt(np.random.random(size=self.size)) * self.radius
        phi = phi.tolist()
        r = r.tolist()
        #transform
        X = []
        Y = []
        i=0
        for i in range(self.size):
            x = r[i] * np.cos(phi[i]) * (1 - (self.radius - norm_r)/self.radius)
            y = r[i] * np.sin(phi[i]) * (1 - (self.radius - norm_r)/self.radius)
            x = self.Xc + np.int(np.round(x))
            y = self.Yc + np.int(np.round(y))
            X.append(x)
            Y.append(y)
        cords_set = np.column_stack((X,Y))
        cords_set = cords_set.tolist()
        return cords_set
if __name__ == "__main__":
    cor_gen = coordinate_gen(25,26,0,12) 
    cords_set = cor_gen.randpoint(24)  # input: the maximum reaching radius of each subject

#%%
import pandas as pd
coordinates = pd.DataFrame(cords_set)
path = "C:/Users/sibo0/OneDrive - Nanyang Technological University (1)/HRI software/reaching and placing task/src/d01_data/01_raw/"
coordinates.to_csv(path + "coordinates_xin2.csv",index=False, index_label=False,header=False)
