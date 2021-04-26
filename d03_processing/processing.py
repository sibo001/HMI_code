# -*- coding: utf-8 -*-
"""
Created on Tue Dec 15 09:38:50 2020

@author: sibo0
"""
import numpy as np
import scipy.io
import pandas as pd
import matplotlib.pyplot as plt
import pickle
import seaborn as sns   

from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.svm import SVR
from src.d00_utils.functions import *
from scipy import stats
from scipy import signal

import sys
import os
#%% CONVERT .MAT FILE TO .CSV FILE
subnum='2'
trialname_list='1','2','3','4','5','6'
for trialname in trialname_list:
    convertfile(subnum,trialname)
#%% READ AND EXTRACT FEATURES FROM TEST DATA
"""
READ AND EXTRACT FEATURES FROM TEST DATA

"""

# list of the subject numbers in the data files
filename_list = ['3']

# initialise dictionaries
extracted_features = {}
df_trajectories = {}

# Define the segment cut-off point, this is based on the angular position 
# angle_cutoff = [1,2,5,10]

# # define number of extracted points from segment
# num_of_extracted_points = 10

# # similarity score between MJT and 
# sim_score = 0.85

# # threshold for outliers to be removed (percentage of number of columns containing an outlier in that row)
# outlier_threshold= 0.2 

# # initialise index
# i = 0

# # Name to save final dictionary of datasets (one dataset per time window)
# filename_seg_save = 'dict.datasets_segments_'+str(num_of_extracted_points)+'points'+'_change_filter3'
# filename_traj_save = 'dict.datasets_trajectories_'+str(num_of_extracted_points)+'points'+'_change_filter3'

"""
    1. read_file(): reads in the raw data files 
    2. resample(): maybe this is not required anymore?
    3. filter_derivate(): filters all the signals and find the derivative signals
    4. normalise_MVC()
    5. split the trajectories into multiple segments per trajectory (based on number of angle_cutoffs given)
    6. extract features from each segment
: 
"""
for filename in filename_list:

    trial_num_list=['1']#'2','3','4','5','6']
    # if filename == '3':
    #     trial_num_list = ['1','4']
    # else:
    #     trial_num_list = ['1','2']
    
    for trial_num in trial_num_list:
        
        # compile different datafiles into a single dataset (imu, emg, mmg)
        dataset_combined_signals, emg_MVC,position_num = read_file(filename,trial_num)
 #%%         
        ## Resample Dataset
       # dataset_RS = resample(dataset_combined_signals)  
        
        # Filter and find the signal derivatives
        dataset_filtered = filter_derivate(dataset_combined_signals)
#%%        
        ## Normalise to MVC EMG 
        dataset_norm = normalise_MVC(emg_MVC, dataset_filtered)
        
        ##Segment the dataframe based on the position number (Only placing tasks included)
        dataset_Reach, windows, window_seg, segments, subsegments = segment_data(dataset_norm, position_num)
        
        ## Split the dataset into complete trajectories and then split into segments of different time windows
        #traj_segments,df_trajectories[i], df_trajectories_info = segment_data(dataset_norm,angle_cutoff)
#%%        
        # Extract features from segments
        
        # extracted_features[i] = segment_extract_features(traj_segments,df_trajectories_info,filename,trial_num,num_of_extracted_points)
        
        # i = i+1