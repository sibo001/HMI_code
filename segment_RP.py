# -*- coding: utf-8 -*-
"""
Created on Mon Feb 22 20:28:05 2021

@author: sibo0
"""
import numpy as np
import pandas as pd
 

#def segment_data(dataset,position_num):
dataset_norm = normalise_MVC(emg_MVC, dataset_filtered)
dataset_Reach = pd.DataFrame()
dataset_Reach = dataset_norm.loc[dataset_norm['segment_RP'] == 1]  # Acquire all reaching datas in one dataset
#%%
# Segment the   
i=0
ind_pos = 0  # The initial index of position_number
total_pos_num = [1,2,3,4,5,6]
segments={}
segments_cutoff = {}
subsegments= {}
dict_pos_num = {}
#define window lengths (ex: 15*0.006 = 0.09s)
time_cutoff = [15,20,25,30,35]
#%%
placing_num = np.zeros((len(dataset_Reach['time']),1))  # the length of all placing number ("1")
i_discont = 0
for i in range(len(dataset_Reach['time'])):
    if (i!=0) and (dataset_Reach.index[i-1] != dataset_Reach.index[i]-1) and (ind_pos < len(position_num)-1) and (len(subsegments[ind_pos])>20): #len(): get the list number; .iloc() can get the index name
        ind_pos = ind_pos + 1
        i_discont = i
    subsegments[ind_pos] = dataset_Reach.iloc[i_discont:i+1]
    placing_num[i,0] = position_num.iloc[ind_pos,0]
    
    dict_pos_num[ind_pos] = np.zeros((len(subsegments[ind_pos]),1))
    dict_pos_num[ind_pos][:] = position_num.iloc[ind_pos,0]
    subsegments[ind_pos].insert(1, 'position_num', dict_pos_num[ind_pos])
    
#%%
#initialise a dictionary for each window length
        
dataset_Reach.insert(1, 'position_num', placing_num)


#%%
# Save all the same position_num in one dataframes and split the dataframe of segmens based on the time slot
 # split the dataframe of segments based on the time slot

for j in range(len(total_pos_num)):
    segments[j]= dataset_Reach.loc[dataset_Reach['position_num'] == j+1]
        
#%%
a=pd.DataFrame()
for window in range(len(subsegments)):
    a =a.append(subsegments[window].drop(subsegments[window].index[20:], axis=0))
#%%
total_pos_num = [1,2,3,4,5,6]
for j in range(len(total_pos_num)):
    segments[j]= a.loc[a['position_num'] == j+1]
    
        
        
        