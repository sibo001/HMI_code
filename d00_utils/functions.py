#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 30 13:17:40 2020

@author: sibo0
"""
import pandas as pd
import numpy as np
from collections import Counter
from sklearn import preprocessing
from collections import Counter
from sklearn.ensemble import RandomForestRegressor, AdaBoostRegressor, GradientBoostingRegressor, ExtraTreesRegressor, VotingRegressor, RandomForestClassifier, GradientBoostingClassifier

from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier, RadiusNeighborsClassifier
from sklearn.tree import DecisionTreeRegressor, DecisionTreeClassifier, ExtraTreeClassifier
from sklearn.neural_network import MLPRegressor, MLPClassifier
from sklearn.svm import SVR, SVC
from sklearn.model_selection import GridSearchCV, cross_val_score, StratifiedKFold, learning_curve, KFold
from sklearn.linear_model import ElasticNetCV, LassoCV, RidgeCV, Ridge, ElasticNet, Lasso, SGDClassifier, RidgeClassifier, RidgeClassifierCV, LogisticRegression, LogisticRegressionCV, RidgeClassifierCV
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.pipeline import make_pipeline
# In[] CONVERT .MAT FILE TO .CSV FILE
# def convertfile(sub_num,trialname):
#     import scipy.io
#     rootdir ="C:/Users/sibo0/OneDrive - Nanyang Technological University (1)/HRI software/reaching and placing task/src/d01_data/01_raw/sub_"+ sub_num
#     csvdir="C:/Users/sibo0/OneDrive - Nanyang Technological University (1)/HRI software/reaching and placing task/src/d01_data/01_raw/sub_"+ sub_num +"/patient_Haojie_17_02_MVC/"
#     data = scipy.io.loadmat(rootdir+"/time/Trial_"+trialname+".mat")

#     for i in data:
#         if '__' not in i and 'readme' not in i:
#             np.savetxt((csvdir +"/Trial_"+trialname+".csv"),data[i],delimiter=',')
#     return
# In[]
def read_file(sub_num, trial_num, name_date):
    
    """
    1. Read in the files using the subject number and the trial number
    2. Removes repeated values from the amplitudes command
    3. Labels axes and combines dataframes into one
    
    Input: 
        sub_num: subject number used to label data folder
        trial_num: the number of the trial
        
    Output:
        combined_dataset: data combined into one dataframe (for 1 trial, 1 subject)
    
    """
    
    import pandas as pd
    
    # global amplitudes
    
    # Define path to the data
    #path= "D:/Yang sibo/HRI software/HRI software/reaching and placing task/src/d01_data/01_raw/sub_"+sub_num
    path = "F:/HRI software/reaching and placing task/src/d01_data/01_raw/sub_"+sub_num
    #path = "C:/Users/sibo0/OneDrive - Nanyang Technological University (1)/HRI software/reaching and placing task/src/d01_data/01_raw/sub_"+sub_num
    
    
    # Read in the different files
    
    # (the mmg signal and the imu and combined): imu, emg and mmg signal
    # emg_MVC (MVC = Maximum Voluntary Contraction): this file is used to normalise the muscle activity between subjects
    # segment_RP :
        #           0: placing task
        #           1: reaching task and taking back
    
    imu = pd.read_csv(path+"/patient_" + name_date + "_exp1/imu/Trial_"+trial_num +".csv",header=None)
    emg = pd.read_csv(path+'/patient_' + name_date + '_exp1/emg/Trial_'+trial_num+'.csv', header=None)
    mmg = pd.read_csv(path+'/patient_' + name_date + '_exp1/mmg/Trial_'+trial_num+'.csv', header=None)
    segment_RP = pd.read_csv(path+'/patient_' + name_date + '_exp1/switch/Trial_'+trial_num+'.csv', header=None)
    emg_MVC = pd.read_csv(path+'/patient_'+ name_date + '_MVC/emg/emg_MVC.csv', header=None)
    mmg_MVC = pd.read_csv(path+'/patient_'+ name_date + '_MVC/mmg/mmg_MVC.csv', header=None)
    position_num = pd.read_csv(path+'/position_num' + trial_num + '.csv', header=None)
    coordinate = pd.read_csv(path+'/coordinates' + trial_num + '.csv', header=None)
    
    # the position_num file column: column 0 = position command to person 
    # the amplitude file column: 0 simulation time of the trial, column 1 = amplitude commanded to person
    
    # find the commands which are sent to the subject (they repeat for as long as it was shown to the user)
    # amplitude2 = amplitude[amplitude.iloc[:,1] != 0]
    
    #create a new list to find the order of each command without repeats
    # amplitudes = []
    # amplitudes.append(amplitude2.iloc[0,1])
    
    # # find if the next command is the same as the previous command
    # for i in range(len(amplitude2)-1):
    #     if (amplitude2.iloc[i,1] != amplitude2.iloc[i+1,1]):
    #         amplitudes.append(amplitude2.iloc[i+1,1])
    
    # label columns of emg dataframe
    # emg = emg[(emg!=0).any()]
    # emg = emg.dropna()
    emg.columns = ['Time','Biceps','Triceps','Deltoid','Pecs']
    
    # label columns of emg_MVC dataframe
    # emg_MVC = emg_MVC[(emg_MVC.T!=0).any()]
    # emg_MVC = emg_MVC.T 
    # emg_MVC = emg_MVC.dropna()
    emg_MVC.columns = ['Time','Biceps','Triceps','Deltoid','Pecs']

    # label columns of imu dataframe
    # imu = imu.T  #Matalb load file
    imu = imu.dropna()
    imu.columns = ['time','elbowflexion','elbowzaxis','shoulderelevation','shoulderazimuth','shoulderzaxis',
                   'trunkflexion','trunklateral','trunkrotation', 'QUATw_trunk', 'QUATx_trunk', 'QUATy_trunk', 'QUATz_trunk', 'QUATw_shoulder', 
                   'QUATx_shoulder', 'QUATy_shoulder', 'QUATz_shoulder', 'QUATw_forearm', 'QUATx_forearm', 'QUATy_forearm', 'QUATz_forearm']
    # label columns of mmg dataframe
    # mmg = mmg.T
    # mmg = mmg.dropna()
    mmg.columns=['Time','mmg']
    
    # label columns of 
    # mmg_MVC = mmg.dropna()
    mmg_MVC.columns=['Time','mmg_MVC']
    # label columns of switch dataframe. The switch is used for segmenting the reaching and placing task
    # segment_RP = segment_RP.T
    segment_RP.columns=['Time','segment_RP']
    
    
    # combine the dataframes into one 
    combined_dataset = imu
    combined_dataset['segment_RP'] =segment_RP['segment_RP']
    combined_dataset['mmg'] = mmg['mmg']
    combined_dataset['Biceps'] = emg['Biceps']
    combined_dataset['Triceps'] = emg['Triceps']
    combined_dataset['Deltoid'] = emg['Deltoid']
    combined_dataset['Pecs'] = emg['Pecs']
    
    return combined_dataset, emg_MVC,mmg_MVC, position_num, coordinate
# In[]
def resample(dataset):
    
    """
    This function downsamples the signals in the original signals to 100 Hz.
    
    """
    
    import scipy
    import numpy as np
    from scipy import signal
    import pandas as pd
    
    #a = dataset[dataset['time'] == 1200.0].index
    #dataset.drop(a , inplace=True)
    
    # resamples the signals to 100Hz:
    
    dataset = dataset.loc[:200000];
    
    resampled_stretch = scipy.signal.resample(dataset.iloc[:,2],120001)
    resampled_imu = scipy.signal.resample(dataset.iloc[:,1],120001)
    resampled_BB = scipy.signal.resample(dataset.iloc[:,3],120001)
    resampled_TB = scipy.signal.resample(dataset.iloc[:,4],120001)
    resampled_D = scipy.signal.resample(dataset.iloc[:,5],120001)
    resampled_P = scipy.signal.resample(dataset.iloc[:,6],120001)
    
    # Define new time signal
    time = np.linspace(0,12000*0.1,120001)

    dataset = pd.DataFrame({'time': time, 'stretch': resampled_stretch, 'imu': resampled_imu, 'biceps': resampled_BB,\
                            'triceps': resampled_TB, 'deltoid': resampled_D, 'pecs': resampled_P})
    
    # rounds away floating point inaccuracies
    decimals = 2 
    dataset['time'] = dataset['time'].apply(lambda x: round(x, decimals))
    dataset['imu'] = dataset['imu'].apply(lambda x: round(x, decimals))
    
    return dataset
    

def filteremg(time, emg, low_pass=20, sfreq=166.7, high_band=5, low_band=49, graphs=1):
    #low_pass=30, sfreq=166.7, high_band=10, low_band=49, graphs=1
    import scipy as sp
    import matplotlib.pyplot as plt
    
    
    """
    Create bandpass filter to filter emg, returns filtered emg signal
    
    time: time data
    emg: EMG data
    high: high-pass cut off frequency
    low: low-pass cut off frequency
    sfreq: sampling frequency
    """
    
    # normalise cut-off to sfreq
    high_band = high_band/(sfreq/2)
    low_band = low_band/(sfreq/2)
    
    # create bandpass filter
    b1, a1 = sp.signal.butter(4, [high_band,low_band], btype='bandpass')
    
    # apply forward backward filtering filtfilt
    emg_filtered = sp.signal.filtfilt(b1, a1, emg)    
    
    # rectify
    emg_rectified = abs(emg_filtered)
    
    # apply low pass filter to rectified signal
    low_pass = low_pass/sfreq
    b2, a2 = sp.signal.butter(4, low_pass, btype='lowpass')
    emg_envelope = sp.signal.filtfilt(b2, a2, emg_rectified)
    
    if graphs == 1:
        
        range_slt = 400
        plt.subplot(1,2,1)
        plt.plot(time[0:range_slt],emg[0:range_slt])
        
        plt.subplot(1,2,2)
        plt.plot(time[0:range_slt],emg_envelope[0:range_slt])
        
        plt.show()

    return emg_envelope

def filtermmg(time, mmg, sfreq=166.7, high_band=20, low_band=50, graphs=1):
    import scipy as sp
    import matplotlib.pyplot as plt
    
    
    """
    Create bandpass filter to filter mmg, returns filtered mmg signal
    
    time: time data
    mmg: MMG data
    high: high-pass cut off frequency
    low: low-pass cut off frequency
    sfreq: sampling frequency
    """
    
    # normalise cut-off to sfreq 
    high_band = high_band/(sfreq/2)
    low_band = low_band/(sfreq/2)
    
    # create bandpass filter
    b1, a1 = sp.signal.butter(4, [high_band,low_band], btype='bandpass')
    
    # apply forward backward filtering filtfilt
    mmg_filtered = sp.signal.filtfilt(b1, a1, mmg)    
    
    # rectify
    mmg_rectified = abs(mmg_filtered)
    
    # # apply low pass filter to rectified signal
    # low_pass = low_pass/sfreq
    # b2, a2 = sp.signal.butter(4, low_pass, btype='lowpass')
    # emg_envelope = sp.signal.filtfilt(b2, a2, emg_rectified)
    if graphs == 1:
        
        range_slt = 400
        plt.subplot(1,2,1)
        plt.plot(time[0:range_slt],mmg[0:range_slt])
        
        plt.subplot(1,2,2)
        plt.plot(time[0:range_slt],mmg_rectified[0:range_slt])
        
        plt.show()    
    
    return mmg_filtered

def lowpass_filter(time, signal, order, low_pass, sfreq): #order:1 low_pass:10 sfreq:166.7
    
    import scipy as sp
    #import matplotlib.pyplot as plt
    
    """ 
    create a low pass filter
    
    """
    
    # create lowpass filter and apply to rectified signal to get EMG envelope
    low_pass = low_pass/sfreq
    b, a = sp.signal.butter(order, low_pass, btype='lowpass')
    filtered_signal = sp.signal.filtfilt(b, a, signal) #imu_rectified)
    
    # plt.figure(1, figsize=(15,8))
    # plt.subplot(2,5,1)
    # plt.plot(time[0:10000],signal[0:10000])
    # plt.subplot(2,5,2)
    # plt.plot(time[0:10000],filtered_signal[0:10000])
    # plt.subplot(2,5,3)
    # plt.plot(time[0:1000],signal[0:1000])
    # plt.subplot(2,5,4)
    # plt.plot(time[0:1000],filtered_signal[0:1000])
    # plt.subplot(2,5,5)
    # plt.plot(time[0:1000],signal[0:1000])
    # plt.plot(time[0:1000],filtered_signal[0:1000],'r')
    # plt.show()
    
    return filtered_signal

def filter_derivate(dataset):
    
    """
    1. filter the imu and emg signals in the dataset
    2. defines the differentials of the imu signal to find velocity and acceleration
    3. filters the emg signals and finds the derivatives
    
    """
    
    import numpy as np
    #import matplotlib.pyplot as plt
    
    # define new dataset based on the input dataset
    dataset = dataset[:-1]
    new_dataset = dataset.copy()
    ## IMU filtering
    
    # filter the signal of elbow and relabel as 'elbow a_p,elbow z' and drop the old column called 'elbowflexion' and 'elbowzaxis'
    # new_dataset['elbow a_p'] = lowpass_filter(new_dataset['time'],new_dataset['elbowflexion'],2,2,166.7)
    # new_dataset.drop('elbowflexion',axis=1,inplace=True)
    # new_dataset['elbow z'] = lowpass_filter(new_dataset['time'],new_dataset['elbowzaxis'],2,2,166.7)
    # new_dataset.drop('elbowzaxis',axis=1,inplace=True)
    # # filter the signal of shoulder and relabel as 'shoulder a_p', 'shoulder az_p' and 'shoulder z' and drop the old column
    # new_dataset['shoulder el_p'] = lowpass_filter(new_dataset['time'],new_dataset['shoulderelevation'],2,2,166.7)
    # new_dataset.drop('shoulderelevation',axis=1,inplace=True)
    # new_dataset['shoulder az_p'] = lowpass_filter(new_dataset['time'],new_dataset['shoulderazimuth'],2,2,166.7)
    # new_dataset.drop('shoulderazimuth',axis=1,inplace=True)
    # new_dataset['shoulder z'] = lowpass_filter(new_dataset['time'],new_dataset['shoulderzaxis'],2,2,166.7)
    # new_dataset.drop('shoulderzaxis',axis=1,inplace=True)
    # # filter the signal of trunk angles of flexion, lateral and rotation
    # new_dataset['trunk f_p'] = lowpass_filter(new_dataset['time'],new_dataset['trunkflexion'],2,2,166.7)
    # new_dataset.drop('trunkflexion',axis=1,inplace=True)
    # new_dataset['trunk l_p'] = lowpass_filter(new_dataset['time'],new_dataset['trunklateral'],2,2,166.7)
    # new_dataset.drop('trunklateral',axis=1,inplace=True)
    # new_dataset['trunk r_p'] = lowpass_filter(new_dataset['time'],new_dataset['trunkrotation'],2,2,166.7)
    # new_dataset.drop('trunkrotation',axis=1,inplace=True)
    
    # define the angular velocity of elbow, shoulder and trunk based on the difference between points divided by sampling time
    vel_e_f = np.diff(new_dataset['elbowflexion'],1)/0.006  #elbow flexion velocity (e_f)
    vel_s_e = np.diff(new_dataset['shoulderelevation'],1)/0.006 # shoulder elevation velocity (s_e)
    vel_t_f = np.diff(new_dataset['trunkflexion'],1)/0.006 #trunk flexion velocity (t_f)
    # add a last value to the end to make lengths equal
    vel_e_f = np.append(vel_e_f,0)
    vel_s_e = np.append(vel_s_e,0)
    vel_t_f = np.append(vel_t_f,0)
    # filter the angular velocity signal
    
    # new_dataset['elbow a_v'] = lowpass_filter(new_dataset['time'],vel_e,2,7,100)
    # new_dataset['shoulder el_v'] = lowpass_filter(new_dataset['time'],vel_s,2,7,100)
    # new_dataset['trunk f_v'] = lowpass_filter(new_dataset['time'],vel_t,2,7,100)
    new_dataset['elbow fl_v'] = vel_e_f
    new_dataset['shoulder el_v'] = vel_s_e
    new_dataset['trunk fl_v'] = vel_t_f
    
    # define the angular acceleration based on the change in velocity divded by sampling time
    acc_e_f = np.diff(new_dataset['elbow fl_v'],1)/0.006
    acc_s_e = np.diff(new_dataset['shoulder el_v'],1)/0.006
    acc_t_f = np.diff(new_dataset['trunk fl_v'],1)/0.006
    
    # add 0 to make lengths equal
    acc_e_f = np.append(acc_e_f,0)
    acc_s_e = np.append(acc_s_e,0)
    acc_t_f = np.append(acc_t_f,0)
    ## filter angular acceleration 
    # new_dataset['elbow a_acc'] = lowpass_filter(new_dataset['time'],acc_e,2,9,100)
    # new_dataset['shoulder el_acc'] = lowpass_filter(new_dataset['time'],acc_s,2,9,100)
    # new_dataset['trunk f_acc'] = lowpass_filter(new_dataset['time'],acc_t,2,9,100)
    new_dataset['elbow fl_acc'] = acc_e_f    #elbow flexion
    new_dataset['shoulder el_acc'] = acc_s_e #shoulder elevaiton
    new_dataset['trunk fl_acc'] = acc_t_f       #trunk flexion
    # define the stretch derivatives and filter
    # new_dataset['stretch'] = lowpass_filter(new_dataset['time'],new_dataset['stretch'],2,4,100)
    # new_dataset['stretch_d'] = np.append(np.diff(new_dataset['stretch'],1)/0.01,0)
    # new_dataset['stretch_dd'] =np.append(np.diff(new_dataset['stretch_d'],1)/0.01,0)
    
    # filter emg
    biceps_filtered = filteremg(new_dataset['time'],new_dataset['Biceps'])
    triceps_filtered = filteremg(new_dataset['time'],new_dataset['Triceps'])
    deltoid_filtered = filteremg(new_dataset['time'],new_dataset['Deltoid'])
    pecs_filtered = filteremg(new_dataset['time'],new_dataset['Pecs'])
    
    new_dataset['biceps']=biceps_filtered
    new_dataset['triceps']=triceps_filtered
    new_dataset['deltoid']=deltoid_filtered
    new_dataset['pecs']=pecs_filtered
    
    # find the derivative for emg signals
    new_dataset['biceps_d']=np.append(np.diff(new_dataset['biceps'],1)/0.01,0)
    new_dataset['triceps_d']=np.append(np.diff(new_dataset['triceps'],1)/0.01,0)
    new_dataset['deltoid_d']=np.append(np.diff(new_dataset['deltoid'],1)/0.01,0)
    new_dataset['pecs_d']=np.append(np.diff(new_dataset['pecs'],1)/0.01,0)
    
    new_dataset['biceps_dd']=np.append(np.diff(new_dataset['biceps_d'],1)/0.01,0)
    new_dataset['triceps_dd']=np.append(np.diff(new_dataset['triceps_d'],1)/0.01,0)
    new_dataset['deltoid_dd']=np.append(np.diff(new_dataset['deltoid_d'],1)/0.01,0)
    new_dataset['pecs_dd']=np.append(np.diff(new_dataset['pecs_d'],1)/0.01,0)
    
    # filter mmg and find the derivative for mmg signals
    mmg_filtered = filtermmg(new_dataset['time'], new_dataset['mmg'])
    new_dataset['mmg_fil']= mmg_filtered
    new_dataset['mmg_d'] = np.append(np.diff(new_dataset['mmg_fil'],1)/0.01,0)
    new_dataset['mmg_dd'] = np.append(np.diff(new_dataset['mmg_d'],1)/0.01,0)
    
    return new_dataset

def segment_data(dataset, position_num):
    
    import numpy as np
    import pandas as pd
    
    """
    Segment the dataframe based on the position number 
    segment_RP=0 (Placing)
    segment_RP=1 (Reaching)
    
    """
    dataset_Reach = pd.DataFrame()
    dataset_Place = pd.DataFrame()
    
    dataset_Place = dataset.loc[dataset['segment_RP'] == 0]  # Acquire all placing datas in one dataset
    dataset_Reach = dataset.loc[dataset['segment_RP'] == 1]  # Acquire all reaching datas in one dataset

    start_time = 60   # (sec) the rough starting time of experiment
    ind_pos = 0  # The initial index of position_number  
    list_pos_num = [1,2,3,4,5,6,7,8,9,10,11,12] #The list of position number
    segments={}
    subsegments={}
    dict_pos_num = {}
    i_discount = 0
    total_row_pl = np.zeros((len(dataset_Place['time']),1)) #total rows during placing time
    windows=pd.DataFrame()
    window_seg = {}    
    cutoff_Index = 25    # the cutoff time for the training data selection (1 step => 0.006s)
    # Save all the rows with the same 'position_num' into one dataframe
    
    
    list_df_place = [d for _, d in dataset_Place.groupby(dataset_Place.index - np.arange(len(dataset_Place)))] # split the dataset_place based on consecutive index

    list_df_reach = [d for _, d in dataset_Reach.groupby(dataset_Reach.index - np.arange(len(dataset_Reach)))]
    
    filt_list_place = []
    for i in range(len(list_df_place)):
        if len(list_df_place[i]) >=50:
            filt_list_place.append(list_df_place[i])
    
    filt_list_reach = []
    for i in range(len(list_df_reach)):
        if len(list_df_reach[i]) >=50:
            filt_list_reach.append(list_df_reach[i])
        
        
    # for i in range(len(dataset['time'])):        # dataset.loc[dataset['time'] == start_time].index[0],# eliminate the first 60 sec dataset.
    #     if (i!=0) and (dataset_Place.index[i-1] != dataset_Place.index[i]-1) and (len(subsegments[ind_pos])>40) and (ind_pos < len(position_num)-1): #len(): get the list number; .iloc() can get the index name
    #         ind_pos = ind_pos + 1
    #         i_discont = i
    #     subsegments[ind_pos] = dataset_Place.iloc[i_discont:i+1]         # segment the dataset regarding the position number
    #     total_row_pl[i,0] = position_num.iloc[ind_pos,0]
        
    #     dict_pos_num[ind_pos] = np.zeros((len(subsegments[ind_pos]),1))
    #     dict_pos_num[ind_pos][:] = position_num.iloc[ind_pos,0]
    #     subsegments[ind_pos].insert(1, 'position_num', dict_pos_num[ind_pos])

    # dataset_Place.insert(1, 'position_num', total_row_pl)
    
    # # Drop other colums and only record the first 20 rows of data (waiting for training)

    # for count in range(len(subsegments)):
    #     windows =windows.append(subsegments[count].drop(subsegments[count].index[cutoff_Index:], axis=0))
        
    # for j in range(len(list_pos_num)):
    #     window_seg[j]= windows.loc[windows['position_num'] == j+1]
        
    
    # return dataset_Place, dataset_Reach, windows, window_seg, segments, subsegments
    return

# def segment_data(dataset,amplitude):
    
#     import numpy as np
#     import pandas as pd
    
#     """
#     Split the trajectories in dataset into segments with different window lengths (defined by different cut-off elbow angles)
    
#     """
    
#     # define window lengths
#     angle_cutoff = [2,5,10,15]
    
#     # intialise variables
#     count = 0
#     #amplitude_var = np.zeros(len(dataset))
#     amplitude_temp = []
#     amplitude_change =[]
#     half_amplitude_change = []
    
#     start_angle = []
#     traj_segment ={}
#     trajectory = {}
#     trajectory_temp = {}
#     segments = {}
    
#     time_start = []
#     time_half = []
#     time_end = []
    
#     peak_segment_velocity = []
#     mean_segment_velocity = []
#     segment_max_point = []
#     segment_cut_off = []
    
#     # initialise a dictionary for each segment
    
#     for j in range(0,len(angle_cutoff)):
#         segments[j] = {}

#     # loop over the dataset and locate the trajectory and then segment that trajectory into segments 
    
#     # there is nothing in the first 8 seconds and the dataset finishes at 12000.0 so ignore these
    
#     for j in range(0,len(dataset['time'])):
#       if (dataset['time'][j] % 8.0 == 0.0) & (dataset['time'][j] != 0.0) & (dataset['time'][j] != 1200.0): #& (dataset['imu'][j] < 5):
          
#           # Define initial trajectory
#           trajectory_temp[count] = dataset.iloc[j:j+700,:] #400
#           ap_col = trajectory_temp[count].columns.get_loc("elbow a_p")
#           av_col = trajectory_temp[count].columns.get_loc("elbow a_v")
          
#           f = trajectory_temp[count].loc[((trajectory_temp[count].iloc[:,ap_col] > np.max(trajectory_temp[count].iloc[:,ap_col]-5)))] #& (trajectory_temp[count].iloc[:,-2]>0))] 
          
#           end = f.index[0]- dataset.index[j]                               
#           #trajectory[count] = trajectory_temp[count].iloc[0:f.index[0]]
                 
#           # Define the end point of the trajectory:
#           #amp_range = trajectory[count].loc[(trajectory[count]['angular position'] > max_amp-5)]
          
#           end_traj = trajectory_temp[count][(end-50):]
          
#           amp_range = end_traj.loc[(end_traj['elbow a_v'] < 1.0+min(abs(end_traj.iloc[:,-2])))] #0.99*max(end_traj.iloc[:,-3]))] 
#           end_amplitude_index = amp_range.index[0]
              
#           a = trajectory_temp[count].loc[(trajectory_temp[count].iloc[:,av_col] > 1.0)]   #&(trajectory[count]['angular velocity']>0)]  
          
#           start_amplitude_index_temp = a.index[0]
          
#           # Segment trajectory:        
#           trajectory_temp[count] = dataset.iloc[start_amplitude_index_temp:end_amplitude_index,:]#end_amplitude_index,:]
          
#           mean_velocity_temp = np.mean(trajectory_temp[count]['angular velocity'])  
#           start_amplitude_index = start_amplitude_index_temp#-int((mean_velocity_temp//2))
#           end_amplitude_index = end_amplitude_index#+int((mean_velocity_temp//2))
          
#           trajectory[count] = dataset.iloc[start_amplitude_index_temp:end_amplitude_index,:] #define the elbow flexion trjactory
          
#           # Define window:
          
#           # Measure variables that define the trajectory: 
          
#           # Find the start and end angular position and the change
          
          
#           end_amplitude =  trajectory[count].iloc[-1,ap_col]#trajectory[count].iloc[amp_range_index,-3]
#           start_amplitude = trajectory[count].iloc[0,ap_col]
#           amplitude_change_ = end_amplitude- start_amplitude
#           amplitude_change.append(amplitude_change_)
          
#           # define end of window
          
#           for angle in angle_cutoff:
          
#               cut_off_index = trajectory[count].loc[(trajectory[count].iloc[:,ap_col] < (start_amplitude + angle))].index[-1]
#               segments[angle_cutoff.index(angle)][count] = dataset.iloc[start_amplitude_index:cut_off_index,:]
          
#           # Find the time at half the cycle
#           d = trajectory[count].loc[((trajectory[count]['angular position'] - start_amplitude) < (amplitude_change_/2))]
          

#           half_time_ = d.iloc[-1,0]- trajectory[count].iloc[0,0]
#           amplitude_half = d.iloc[-1,ap_col] #- start_amplitude
          
#           time_half.append(half_time_)
            
#           # Find the amplitude at halfway
#           #amplitude_half = d.iloc[-1,ap_col] - start_amplitude
#           half_amplitude_change.append(amplitude_half)
          
#           # Find peak and mean velocity
#           peak_velocity = np.max(trajectory[count]['angular velocity'])   #np.max(np.diff(dataset[j:j+400]['imu'],1))/0.01
#           #mean_velocity = np.mean(trajectory[count]['angular velocity'])  
#           mean_velocity = amplitude_half/half_time_
          
#           peak_segment_velocity.append(peak_velocity)
#           mean_segment_velocity.append(mean_velocity)
          
#           segment_cut_off.append(start_amplitude_index)
#           segment_max_point.append(end_amplitude_index)
          
#           # Find the start position
#           start_angle.append(start_amplitude)
          
#           time_start_ = trajectory[count].iloc[0,0]
#           time_end_ = trajectory[count].iloc[-1,0]-time_start_
          
#           #time_start.append(time_start_)
#           time_end.append(time_end_)
          
#           count=count+1
          
#     peak_segment_velocity = [ round(elem, 2) for elem in peak_segment_velocity ]
#     time_end = [ round(elem, 2) for elem in time_end ]
#     time_half = [ round(elem, 2) for elem in time_half ]

# #          
#     dict = {'amplitude_change': amplitude_change, 'peak_velocity': peak_segment_velocity, 'mean_velocity': mean_segment_velocity, \
#             'time_half':time_half, 'time_end':time_end, 'segment_cut_off':segment_cut_off, 'segment_max_point':segment_max_point, 'start_angle':start_angle}
        
#     df = pd.DataFrame(dict)
        
#     return segments, trajectory,df #traj_segment

def plot_segments(segments, peak_amplitude, peak_velocity):
    
    import matplotlib.pyplot as plt
    
    for i in range(0,20):
        
        plt.figure(i,figsize=(15,4)) 
        
        #plt.subtitle('Peak Velocity: ' +str(peak_velocity[i]) +' , Peak Amplitude: '+ str(peak_amplitude[i]))
        plt.subplot(1,6,1)
        plt.plot(segments[i]['time'],segments[i]['angular position'])
        #plt.ylim(0,10)
        
        plt.subplot(1,6,2)
        plt.plot(segments[i]['time'],segments[i]['angular velocity'])
        #plt.ylim(0,10)
        
        plt.subplot(1,6,3)
        plt.plot(segments[i]['time'],segments[i]['angular acceleration'])
        #plt.ylim(0,10)
        
        plt.subplot(1,6,4)
        plt.plot(segments[i]['time'],segments[i]['stretch'])
#        plt.ylim(3.324,3.32)
        
        plt.subplot(1,6,5)
        plt.plot(segments[i]['time'],segments[i]['biceps'])
        #plt.ylim(0.005,0.015)
        
        plt.subplot(1,6,6)
        plt.plot(segments[i]['time'],segments[i]['triceps'])
        #plt.ylim(0.003,0.008)
        
        # plt.subplot(1,6,5)
        # plt.plot(segments[i]['time'],segments[i]['deltoid'])
        # #plt.ylim(0.002,0.004)
        
        # plt.subplot(1,6,6)
        # plt.plot(segments[i]['time'],segments[i]['pecs'])
        # #plt.ylim(0.003,0.005)
        
        plt.show()
    
    return 0

def plot_traj(trajectory,segment_line, segment_max_point):
    
    import matplotlib.pyplot as plt
    
    
    for segment_num in range(0,20):
        
        segment_line[segment_num] = segment_line[segment_num] + trajectory[segment_num].iloc[0,0]
        segment_max_point[segment_num] = segment_max_point[segment_num] + trajectory[segment_num].iloc[0,0]
        
        
        #plt.plot(trajectory[segment_num]['time']-trajectory[segment_num].iloc[0,0],segment_line[segment_num])
        
        plt.figure(segment_num,figsize=(15,4)) 
        #plt.suptitle('Peak Velocity: ' +str(peak_velocity[segment_num]) +' , Peak Amplitude: '+ str(peak_amplitude[segment_num]))
        
        time = trajectory[segment_num]['time']#-trajectory[segment_num].iloc[0,0]
        
        plt.subplot(1,6,1)
        plt.plot(time,trajectory[segment_num]['angular position'])
        plt.title('segment cuff off: {} and trajectory max point = {}'.format(segment_line[segment_num], segment_max_point[segment_num]))
        
        plt.subplot(1,6,2)
        plt.plot(time,trajectory[segment_num]['angular velocity'])
        
        plt.subplot(1,6,3)
        plt.plot(time,trajectory[segment_num]['angular acceleration'])
        
        plt.subplot(1,6,4)
        plt.plot(time,trajectory[segment_num]['stretch'])
#        plt.ylim(3.324,3.32)
        
        plt.subplot(1,6,5)
        plt.plot(time,trajectory[segment_num]['biceps'])
        #plt.ylim(0.005,0.015)
        
        plt.subplot(1,6,6)
        plt.plot(time,trajectory[segment_num]['triceps'])
        #plt.ylim(0.003,0.008)
        
        # plt.subplot(1,6,5)
        # plt.plot(time,trajectory[segment_num]['deltoid'])
        # #plt.ylim(0.002,0.004)
        
        # plt.subplot(1,6,6)
        # plt.plot(time,trajectory[segment_num]['pecs'])
        #plt.ylim(0.003,0.005)
        
        
        plt.show()
        
    return 0

# def extract_features(dataset, segments, subsegments):
    
#     import numpy as np
#     import pandas as pd
#     import seaborn as sns
    
    
#     """
#     Define the feature window: 15, 20, 25, 30, 35 rows in the each subsegment
#     New features :  1. total mmg 
#                     2. total imu angle
#                     3. sum of biceps
#                     4. sum of triceps
#                     5. sum of deltoid
#                     6. sum of trunk
#     """
    
#     for subsegment in subsegments:
        
#     return

# def extract_features(segments, df,filename,trial_num):
    
#   import numpy as np
#   import pandas as pd
#   import seaborn as sns
#   import matplotlib.pyplot as plt
#   from scipy import stats
  
#   #peak_amplitude, peak_velocities,  mean_segment_velocity,time_half,time_end
    
#   ## Function to extract features from each segment

#   #   Features: 1. total mmg
#   #             2. total imu
#   #             3. sum of biceps
#   #             4. sum of tricep
#   #             5. etc

#   mmg_sum = []
#   imu_sum = []
#   biceps_sum = []
#   triceps_sum = []
#   deltoid_sum = []
#   pecs_sum = []
#   #amplitude =[]

#   biceps_max = []
#   triceps_max = []
#   deltoid_max = []
  
#   stretch_max = []
#   imu_max = []
#   velocity_max = []
  
#   curr_velocity = []
#   curr_acc = []
#   curr_biceps_change = []
#   curr_biceps_change2 = []
#   curr_triceps_change = []
#   curr_triceps_change2 = []
#   curr_stretch_change = []
#   curr_stretch_change2 = []

#   biceps_diff = []
#   triceps_diff = []
#   deltoid_diff = []
#   stretch_diff = []
#   imu_diff = []
  
#   stretch_gradient = []
#   biceps_gradient = []
#   triceps_gradient = []
#   deltoid_gradient = []
#   pecs_gradient = []
  
#   biceps_min = []
#   biceps_min_time = []
  
#   triceps_min = []
#   deltoid_min = []
  
#   segment_duration = []
#   features_df = {} #pd.DataFrame()
#   df_selected_features = {}
  
#   # New features
  
#   stretch_mean = []
#   bb_mean = []
#   tb_mean =[]
#   ad_mean = []
#   pm_mean =[]
  
#   stretch_var = []
#   bb_var = []
#   tb_var = []
#   ad_var = []
#   pm_var = []
  
#   col = []

#   for i in range(1,7):
#      col.append('time{}'.format(i))
#      col.append('stretch{}'.format(i))
#      col.append('bb{}'.format(i))
#      col.append('tb{}'.format(i))
#      col.append('ad{}'.format(i))
#      col.append('pm{}'.format(i))
#      col.append('pos{}'.format(i))
#      col.append('vel{}'.format(i))
#      col.append('acc{}'.format(i))
      
#      col.append('stretch_d{}'.format(i))
#      col.append('stretch_dd{}'.format(i))
        
#      col.append('bb_d_{}'.format(i))
#      col.append('tb_d_{}'.format(i))
#      col.append('ad_d_{}'.format(i))
#      col.append('pm_d_{}'.format(i))
#      col.append('bb_dd_{}'.format(i))
#      col.append('tb_dd_{}'.format(i))
#      col.append('ad_dd_{}'.format(i))
#      col.append('pm_dd_{}'.format(i))
     
#   for window in range(0,len(segments)):
      
#       features_df[window] = pd.DataFrame()
  
#       for segment_number in range(0,len(segments[window])):
          
#           segment_ind = segments[window][segment_number]
          
#         ## Time
#           segment_duration.append(segment_ind.iloc[-1,0] - segment_ind.iloc[0,0])
          
#         ## Position  
          
#           imu_sum.append(segment_ind['angular position'].sum())
#           imu_max.append(np.max(segment_ind['angular position']))
#           imu_diff.append(segment_ind.iloc[-1]['angular position'] - segment_ind.iloc[0]['angular position'])
          
#         ## Velocity
#           velocity_max.append(np.max(segment_ind['angular velocity']))
#           curr_velocity.append(np.mean(segment_ind.iloc[-30:,-2]))
          
#         ## Acceleration
#           curr_acc.append(np.mean(segment_ind.iloc[-30:,-1]))#[(len(segments[segment_number])-30):]))
          
#         ## Stretch
#           stretch_sum.append(segment_ind['stretch'].sum())
#           stretch_max.append(np.max(segment_ind.iloc[:-10,1]))
#           curr_stretch_change.append(np.mean(np.diff(segment_ind['stretch'],1)[(len(segment_ind)-30):]))
#           curr_stretch_change2.append(np.mean(np.diff(segment_ind['stretch'],2)[(len(segment_ind)-30):]))
#           stretch_diff.append(segment_ind.iloc[-1]['stretch'] - segment_ind.iloc[0]['stretch'])
#           #stretch_gradient.append(np.max(np.diff(segments[segment_number].iloc[:-10,1],1)/0.01))
          
#         ## Biceps
          
#           biceps_sum.append(segment_ind['biceps'].sum())
#           biceps_max.append(np.max(np.abs(segment_ind['biceps'])))
#           curr_biceps_change.append(np.mean(np.diff(segment_ind['biceps'],1)[(len(segment_ind)-30):]))
#           curr_biceps_change2.append(np.mean(np.diff(segment_ind['biceps'],2)[(len(segment_ind)-30):]))
#           #biceps_gradient.append(max(np.diff(segments[segment_number].iloc[:-10,3],1)/0.01))
#           biceps_diff.append(segment_ind.iloc[-1]['biceps'] - segment_ind.iloc[0]['biceps'])
#           biceps_min.append(np.min(segment_ind['biceps']))
#           biceps_min_time.append(segment_ind.loc[segment_ind.idxmin()['biceps']]['time']-segment_ind.iloc[0,0])
           
#         ## Triceps
#           triceps_sum.append(segment_ind['triceps'].sum())
#           triceps_max.append(np.max(np.abs(segment_ind['triceps'])))
#           curr_triceps_change.append(np.mean(np.diff(segment_ind['triceps'],1)[(len(segment_ind)-30):]))
#           curr_triceps_change2.append(np.mean(np.diff(segment_ind['triceps'],2)[(len(segment_ind)-30):]))
#           #triceps_gradient.append(max(np.diff(segments[segment_number].iloc[:-10,4],1)/0.01))
#           triceps_diff.append(segment_ind.iloc[-1]['triceps'] - segment_ind.iloc[0]['triceps'])
#           triceps_min.append(np.min(segment_ind['triceps']))
        
#         ## Deltoid
#           deltoid_sum.append(segment_ind['deltoid'].sum())
#           deltoid_max.append(np.max(np.abs(segment_ind['deltoid'])))
#           #deltoid_gradient.append(max(np.diff(segments[segment_number].iloc[:-10,5],1)/0.01))
#           deltoid_diff.append(segment_ind.iloc[-1]['deltoid'] - segment_ind.iloc[0]['deltoid'])
#           deltoid_min.append(np.min(segment_ind['deltoid']))
          
#         ## Pecs
#           pecs_sum.append(segment_ind['pecs'].sum())
#           #pecs_gradient.append(max(np.diff(segments[segment_number].iloc[:-10,6],1)/0.01))
         
#           """ 
#           Define segment length, split into 6 evenly spaced points
#           Features of each point for each sensor (6):
#             1. time
#             2. position
#             3. velocity 
#             4. acceleration
#             = 24 features
            
#             + mean
#             + var
#           """
          
#           stretch_mean.append(np.mean(segment_ind['stretch']))
#           bb_mean.append(np.mean(segment_ind['biceps']))
#           tb_mean.append(np.mean(segment_ind['triceps']))
#           ad_mean.append(np.mean(segment_ind['deltoid']))
#           pm_mean.append(np.mean(segment_ind['pecs']))
          
#           stretch_var.append(np.var(segment_ind['stretch']))
#           bb_var.append(np.var(segment_ind['biceps']))
#           tb_var.append(np.var(segment_ind['triceps']))
#           ad_var.append(np.var(segment_ind['deltoid']))
#           pm_var.append(np.var(segment_ind['pecs']))
        
#           segment_ind['time'] = np.round([i - segment_ind['time'].iloc[0] for i in segment_ind['time']],2)
        
#           segment_length = len(segment_ind) # in samples
#           indicies = np.round(np.linspace(0,segment_length-1, 6)).astype(int)
#           features_df_ravel = pd.DataFrame(np.array(segment_ind.iloc[indicies,:]).ravel())
#           features_df_single = features_df_ravel.T
#           features_df_single.columns = col
          
#           features_df_single['Peak Amplitude'] = df['amplitude_change'][segment_number] #np.array(df['amplitude_change'])
#           features_df_single['Peak Velocity'] = df['peak_velocity'][segment_number]
#           features_df_single['Mean Velocity'] = df['mean_velocity'][segment_number]
#           features_df_single['T_end'] = df['time_end'][segment_number]
#           features_df_single['T_half'] = df['time_half'][segment_number]
#           features_df_single['Subject_Num'] = int(filename)
#           features_df_single['Trial_Num'] = int(trial_num)
        
#           features_df[window] = features_df[window].append(features_df_single)
              
        
#       dict = {'curr_triceps_change2': curr_triceps_change2, 'curr_biceps_change2': curr_biceps_change2,\
#               'triceps_min':triceps_min, 'triceps_max':triceps_max,'pecs_sum':pecs_sum,\
#               'biceps_sum':biceps_sum,'biceps_max':biceps_max, 'biceps_min':biceps_min, \
#               'curr_velocity':curr_velocity, 'curr_acc':curr_acc, \
#               'segment_duration': segment_duration,'deltoid_sum':deltoid_sum,\
#               'stretch_max':stretch_max}
          
   
#       # 'stretch_gradient':stretch_gradient,
      
#       #'biceps_min':biceps_min,'biceps_sum':biceps_sum, 'curr_biceps_change2': curr_biceps_change2, 'curr_triceps_change2': curr_triceps_change2} 
#       #'window_max_velocity':velocity_max, 'curr_velocity':curr_velocity, 'curr_acc':curr_acc, 'biceps_diff':biceps_diff, 'imu_diff':imu_diff, 'biceps_min':biceps_min, 'biceps_min_time':biceps_min_time } #{'biceps_sum':biceps_sum, 'biceps_max':biceps_max, 'biceps_gradient':biceps_gradient, 'triceps_gradient':triceps_gradient,'stretch_gradient':stretch_gradient, 'imu_diff':imu_diff, 'curr_velocity':curr_velocity, 'curr_acc':curr_acc }
#       #'deltoid_gradient':deltoid_gradient, 'pecs_gradient':pecs_gradient, 'imu_max':imu_max, 'stretch_gradient':stretch_gradient,'stretch_max':stretch_max} # 'stretch_gradient':stretch_gradient, 'window_max_velocity':velocity_max'stretch_gradient':stretch_gradient 'imu_diff':imu_diff 'window_max_velocity':velocity_max}  #'stretch_diff':stretch_gradient #stretch_diff':stretch_diff} #'velocity_max':velocity_max, 'biceps_max':biceps_max, 'triceps_diff':triceps_diff, 'deltoid_diff':deltoid_diff 'velocity_max':velocity_max 'stretch_diff':stretch_diff,'imu_diff':imu_diff,  'triceps_sum':triceps_sum,'deltoid_sum':deltoid_sum,'pecs_sum':pecs_sum,'amplitude':amplitude}
      
#       df_selected_features[window] = pd.DataFrame(dict) 
      
   
  
#   # features_df['stretch_mean'] = stretch_mean
#   # features_df['bb_mean'] = bb_mean
#   # features_df['tb_mean'] = tb_mean
#   # features_df['ad_mean'] = ad_mean
#   # features_df['pm_mean'] = pm_mean

#   # features_df['stretch_var'] = stretch_var
#   # features_df['bb_var'] = bb_var
#   # features_df['tb_var'] = tb_var
#   # features_df['ad_var'] = ad_var
#   # features_df['pm_var'] = pm_var
      


#   #df2 = features_df.copy()
  
#   # df2.columns = col
      
#   #   #df2['End Window Time'] = time_3degrees
       
#   #   #df['peak_segment_velocity'] = peak_segment_velocity
#   # df2['Peak Amplitude'] = np.array(df['amplitude_change'])
#   # df2['Peak Velocity'] = np.array(df['peak_velocity'])
#   # df2['Mean Velocity'] = np.array(df['mean_velocity'])
    
#   #   #df['Time at half traj'] = time_half
#   # df2['Time at end'] = np.array(df['time_end'])
#   # df2['Time at half'] = np.array(df['time_half'])
#   # df2 = df2.reset_index(drop=True)
      
#   #   #df2 = df2[(np.abs(stats.zscore(df2)) < 2).all(axis=1)]
    
#   # #sns.pairplot(df2)
#   # #plt.show()
      
#   return features_df, df_selected_features,col

def MLR(df):

    from sklearn.model_selection import train_test_split
    from sklearn.linear_model import LinearRegression
    from sklearn import preprocessing
    from sklearn import metrics
    
    import pandas as pd
    import numpy as np
    import seaborn as sns
    import matplotlib.pyplot as plt
    
    ##### Train model
    X_org = df.drop(['time','segment_RP'],axis=1)
    
    #y = df['amplitude']
    y = df.loc[:,'position_num']
    
    # Split the data into train and test randomly with the test size = 30%, stratify data to split classification evenly
    X_train, X_test, y_train, y_test = train_test_split(X_org, y, test_size=0.2, random_state=42)
    
    # Scale the train data to range [0 1] and scale the test data according to the train data
    min_max_scaler = preprocessing.MinMaxScaler()
    X_train_scaled = min_max_scaler.fit_transform(X_train)
    X_test_scaled = min_max_scaler.transform(X_test)
    
    lm = LinearRegression()
    lm.fit(X_train_scaled,y_train)
    
    # The coefficients
    print('Coefficients: \n', lm.coef_)
    
    predictions = lm.predict(X_test_scaled)
    df_predictions = pd.DataFrame({'y_test':y_test, 'predictions':predictions})
    
    #plt.scatter(y_test,predictions)
    sns.lmplot(x= 'y_test',y = 'predictions', data = df_predictions)
    plt.xlabel('Y Test')
    plt.ylabel('Predicted Y')
    plt.show()
    
    print('MAE:', metrics.mean_absolute_error(y_test, predictions))
    print('MSE:', metrics.mean_squared_error(y_test, predictions))
    print('RMSE:', np.sqrt(metrics.mean_squared_error(y_test, predictions)))
    
    X_scaled = min_max_scaler.transform(X_org)
    velocity_prediction = lm.predict(X_scaled)
    
    X = X_org.copy()
    X['velocity_prediction'] = velocity_prediction
    
    #X = df.drop(['Peak Amplitude','Peak Velocity'],axis=1)
    
    #y = df['amplitude']
    y = df['Peak Amplitude']
    
    # Split the data into train and test randomly with the test size = 30%, stratify data to split classification evenly
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.70, random_state=42)
    
    # Scale the train data to range [0 1] and scale the test data according to the train data
    min_max_scaler2 = preprocessing.MinMaxScaler()
    X_train_scaled = min_max_scaler2.fit_transform(X_train)
    X_test_scaled = min_max_scaler2.transform(X_test)
    
    lm2 = LinearRegression()
    lm2.fit(X_train_scaled,y_train)
    
    # The coefficients
    print('Coefficients: \n', lm.coef_)
    
    amplitude_predictions = lm2.predict(X_test_scaled)
    df_amplitude_predictions = pd.DataFrame({'y_test':y_test, 'predictions':amplitude_predictions})
    
    #plt.scatter(y_test,predictions)
    sns.lmplot(x= 'y_test',y = 'predictions', data = df_amplitude_predictions)
    plt.xlabel('Y Test')
    plt.ylabel('Predicted Y')
    plt.show()
    
    print('MAE:', metrics.mean_absolute_error(y_test, amplitude_predictions))
    print('MSE:', metrics.mean_squared_error(y_test, amplitude_predictions))
    print('RMSE:', np.sqrt(metrics.mean_squared_error(y_test, amplitude_predictions)))
    
    #X_original_scaled = min_max_scaler.transform(X_original)
    
    scaled_velocity = min_max_scaler.transform(X_org)
    scaled_amplitude = min_max_scaler2.transform(X)
    
    velocity_prediction = lm.predict(scaled_velocity)
    amplitude_prediction = lm2.predict(scaled_amplitude)
    
    df['velocity_prediction'] = velocity_prediction
    df['amplitude_prediction'] = amplitude_prediction
    
    return X_train_scaled, X_test_scaled, y_train, y_test,df

def Support_Vector_Regression(df):
        
    from sklearn.model_selection import train_test_split
    from sklearn import metrics
    from sklearn.svm import SVR
    from sklearn import preprocessing
    from sklearn.metrics import classification_report,confusion_matrix
    import matplotlib.pyplot as plt
    import numpy as np
    import pandas as pd
    import seaborn as sns
    
    X_org = df.drop(['Peak Amplitude','Peak Velocity','Mean Velocity','Time at end', 'Time at half'],axis=1)
    
    #y = df['amplitude']
    y = df[['Peak Velocity','Time at half','Peak Amplitude','Mean Velocity']]
    
    #y.loc['Peak Amplitude'] /= 2
    
    # Split the data into train and test randomly with the test size = 30%, stratify data to split classification evenly
    X_train, X_test, y_train, y_test = train_test_split(X_org, y, test_size=0.30, random_state=42) #random_state=42
    
    #features_int = ['biceps_max'] #'curr_acc' biceps_max','curr_triceps_change2'] #'curr_acc'
    X_train_peak_vel = X_train #[features_int]
    X_test_peak_vel = X_test #[features_int]
    
    y_train_velocity = y_train.iloc[:,0]
    y_train_time = y_train.iloc[:,1]
    y_train_amplitude = y_train.iloc[:,2]
    y_train_mean_vel = y_train.iloc[:,3]
    
    y_test_velocity = y_test.iloc[:,0]
    y_test_time = y_test.iloc[:,1]
    y_test_amplitude = y_test.iloc[:,2]
    y_test_mean_vel = y_test.iloc[:,3]
    
    # Scale the train data to range [0 1] and scale the test data according to the train data
    min_max_scaler = preprocessing.MinMaxScaler()
    X_train_scaled = min_max_scaler.fit_transform(X_train_peak_vel)
    X_test_scaled = min_max_scaler.transform(X_test_peak_vel)
    
    clf = SVR(kernel = 'linear',C= 1, gamma = 1, epsilon=0.01,degree=2) # 10,100
    clf.fit(X_train_scaled, y_train_velocity)
    
    # Generate predictions for test set
    velocity_predictions = clf.predict(X_test_scaled)
    df_velocity_predictions = pd.DataFrame({'y_test':y_test_velocity, 'predictions':velocity_predictions})
        
    # Show cross-val results
    #print(confusion_matrix(y_test,predictions))
    #print(classification_report(y_test,predictions))
    from sklearn.metrics import r2_score
    
    print('Peak Velocity')
    print('MAE:', metrics.mean_absolute_error(y_test_velocity, velocity_predictions))
    print('MSE:', metrics.mean_squared_error(y_test_velocity, velocity_predictions))
    print('RMSE:', np.sqrt(metrics.mean_squared_error(y_test_velocity, velocity_predictions)))
    print('% Error: ', 100*metrics.mean_absolute_error(y_test_velocity, velocity_predictions)/np.mean(y_test_velocity))
    print('Score:', clf.score(X_test_scaled,velocity_predictions),'\n')
    print('R2 Score:', r2_score(y_test_velocity, velocity_predictions),'\n')
    
    #print(classification_report(y_test_velocity, velocity_predictions))
    
    # print('Coefficients: ')
    # pd.set_option('display.max_columns', df.shape[1]+1)
    # coeffs = np.abs(clf.coef_)/np.sum(np.abs(clf.coef_))*100
    # df = pd.DataFrame(data = coeffs, columns = X_train_peak_vel.columns.tolist())
    # df = df.loc[0].abs().sort_values()
    # print(df,'\n')
    
    sns.lmplot(x= 'y_test',y = 'predictions', data = df_velocity_predictions)
    plt.plot([0,200],[0,200],'r',lw=1)
    plt.title('Peak Velocity Prediction')
    
    #plt.scatter(y_test,predictions)
    plt.show()
    
    from sklearn.model_selection import GridSearchCV 
    
    #features_int = ['biceps_max','biceps_sum','curr_acc','curr_velocity','triceps_min', 'curr_triceps_change2', 'pecs_sum','segment_duration'] #'triceps_max','pecs_sum','curr_triceps_change2'\
                   # ,'biceps_sum', 'deltoid_sum'] #'curr_acc'
    
    # print('Features used: ',features_int)
    # X_train_mean_vel = X_train[features_int]
    # X_test_mean_vel = X_test[features_int]
    
    # Scale the train data to range [0 1] and scale the test data according to the train data
    min_max_scaler4 = preprocessing.MinMaxScaler()
    X_train_scaled = min_max_scaler4.fit_transform(X_train)
    X_test_scaled = min_max_scaler4.transform(X_test)
    
    parameters = {'kernel': ['rbf'], 'C':[1,10,100,1000],'gamma': [10,1,1e2],'epsilon':[0.01,0.1,1,10]}

    svr2 = SVR() #kernel = 'poly',C=10,gamma=1,epsilon=0.01,degree=3) # 'rbf',C= 1000, gamma = 0.01, epsilon=0.01,degree=2) #100,1000,10,1
    
    #clf4 = SVR('rbf',C= 100, gamma = 1, epsilon=0.1,degree=2)
    clf4 = GridSearchCV(svr2, parameters)
    
    clf4.fit(X_train_scaled,y_train_mean_vel)
    
    print(clf4.best_params_)
    
    # The coefficients
    #print('Coefficients: \n', lm.coef_)
    
    mean_vel_predictions = clf4.predict(X_test_scaled)
    df_mean_vel_predictions = pd.DataFrame({'y_test':y_test_mean_vel, 'predictions':mean_vel_predictions})
    
    #plt.scatter(y_test,predictions)
    sns.lmplot(x= 'y_test',y = 'predictions', data = df_mean_vel_predictions)
    plt.title('Mean Velocity Prediction')
    #plt.plot([5,50],[5,50],'r',lw=1)
    a = min(y_test_mean_vel)
    b = max(y_test_mean_vel)
    
    plt.plot([a,b],[a,b],'r',lw=1)
    plt.legend(['Predicted Correlation','Real Correlation'])
    
    plt.xlabel('True Mean Velocity (degrees/s)')
    plt.ylabel('Predicted Mean Velocity (degrees/s)')
    plt.savefig("mean_vel_40%.svg",format='svg')
    plt.show()
    
    print('Mean Velocity')
    print('MAE:', metrics.mean_absolute_error(y_test_mean_vel, mean_vel_predictions))
    print('MSE:', metrics.mean_squared_error(y_test_mean_vel, mean_vel_predictions))
    print('RMSE:', np.sqrt(metrics.mean_squared_error(y_test_mean_vel, mean_vel_predictions)))
    print('% Error: ', 100*metrics.mean_absolute_error(y_test_mean_vel, mean_vel_predictions)/np.mean(y_test_mean_vel))
    print('Coefficients: ')
    print('Score:', clf4.score(X_test_scaled,mean_vel_predictions),'\n')
    print('R2 Score:', r2_score(y_test_mean_vel, mean_vel_predictions),'\n')
    
    
    
    # features_int2 = ['biceps_max', 'biceps_sum','biceps_min','curr_acc','curr_velocity','triceps_min', 'pecs_sum','segment_duration']# 'triceps_max','pecs_sum','curr_triceps_change2'\
    #                # ,'biceps_sum', 'deltoid_sum'] #'curr_acc'
    
    # print('Features used: ',features_int2)
    # X_train_dur = X_train[features_int2]
    # X_test_dur = X_test[features_int2]
    
    # X_train_dur['Predicted Mean Velocity'] = clf4.predict(X_train_scaled)
    # X_test_dur['Predicted Mean Velocity'] = clf4.predict(X_test_scaled)
    
    # Scale the train data to range [0 1] and scale the test data according to the train data
    # min_max_scaler2 = preprocessing.MinMaxScaler()
    # X_train_scaled = min_max_scaler2.fit_transform(X_train)
    # X_test_scaled = min_max_scaler2.transform(X_test)
    
    
    parameters = {'kernel': ['rbf'], 'C':[0.01,1,10,100],'gamma': [0.01,0.1,1,10],'epsilon':[0.01,0.1,1]}

    svr3 = SVR()   #clf2 = SVR(kernel = 'rbf',C=100,gamma=1,epsilon=0.1,degree=1) # 'rbf',C= 1000, gamma = 0.01, epsilon=0.01,degree=2) #100,1000,10,1
    
    clf2 = GridSearchCV(svr3, parameters)
    
    clf2.fit(X_train_scaled,y_train_time)
    
    print(clf2.best_params_)
    
    # The coefficients
    #print('Coefficients: \n', lm.coef_)
    
    time_predictions = clf2.predict(X_test_scaled)
    df_time_predictions = pd.DataFrame({'y_test':y_test_time, 'predictions':time_predictions})
    
    #plt.scatter(y_test,predictions)
    sns.lmplot(x= 'y_test',y = 'predictions', data = df_time_predictions)
    plt.title('Duration Prediction')
    
    plt.plot([0.56,2.08],[0.56,2.08],'r',lw=1)
    plt.legend(['Predicted Correlation','Real Correlation'])
    
    plt.xlabel('True Trajectory Duration (s)')
    plt.ylabel('Predicted Trajectory Duration (s)')
    plt.savefig("duration_40%.svg",format='svg')
    plt.show()
    
    print('Duration')
    print('MAE:', metrics.mean_absolute_error(y_test_time, time_predictions))
    print('MSE:', metrics.mean_squared_error(y_test_time, time_predictions))
    print('RMSE:', np.sqrt(metrics.mean_squared_error(y_test_time, time_predictions)))
    print('% Error: ', 100*metrics.mean_absolute_error(y_test_time, time_predictions)/np.mean(y_test_time))
    print('Score:', clf2.score(X_test_scaled,time_predictions),'\n')
    print('R2 Score:', r2_score(y_test_time, time_predictions),'\n')
    
    # print('Coefficients: ')
    # #pd.set_option('display.max_columns', df.shape[1]+1)
    # coeffs2 = np.abs(clf2.coef_)/np.sum(np.abs(clf2.coef_))*100
    # df = pd.DataFrame(data = coeffs2, columns = X_train.columns.tolist())
    # df = df.loc[0].abs().sort_values()
    # print(df,'\n')
    
    #     # Scale the train data to range [0 1] and scale the test data according to the train data
    
    # #features_int = ['curr_acc']
    
    # X_train_amplitude = X_train.copy()
    # X_test_amplitude = X_test.copy()
    
    # #scaled_X_train = min_max_scaler4.fit_transform(X_train)
    # #scaled_X_test = min_max_scaler4.fit_transform(X_test)
    
    # mean_velocity_predictions_train = clf4.predict(X_train_scaled)
    # mean_velocity_predictions_test = clf4.predict(X_test_scaled)
    # peak_velocity_predictions_train = clf.predict(X_train_scaled)
    # peak_velocity_predictions_test = clf.predict(X_test_scaled)
    
    # X_train_amplitude_new = pd.DataFrame()
    # X_test_amplitude_new = pd.DataFrame()
    
    # X_train_amplitude['predicted mean velocity'] = mean_velocity_predictions_train
    # X_test_amplitude['predicted mean velocity'] = mean_velocity_predictions_test
    # X_train_amplitude['predicted peak velocity'] = peak_velocity_predictions_train
    # X_test_amplitude['predicted peak velocity'] = peak_velocity_predictions_test
    
    # min_max_scaler3 = preprocessing.MinMaxScaler()
    # X_train_scaled = min_max_scaler3.fit_transform(X_train_amplitude)
    # X_test_scaled = min_max_scaler3.transform(X_test_amplitude)
    
    # clf3 = SVR(kernel = 'rbf',C=10,gamma=0.1,epsilon=0.01,degree=1) # 'rbf',C= 1000, gamma = 0.01, epsilon=0.01,degree=2) #100,1000,10,1
    # clf3.fit(X_train_scaled,y_train_amplitude)
    
    # # The coefficients
    # #print('Coefficients: \n', lm.coef_)
    
    # amplitude_predictions = clf3.predict(X_test_scaled)
    # df_amplitude_predictions = pd.DataFrame({'y_test':y_test_amplitude, 'predictions':amplitude_predictions})
    
    # #plt.scatter(y_test,predictions)
    # sns.lmplot(x= 'y_test',y = 'predictions', data = df_amplitude_predictions)
    # plt.plot([20,100],[20,100],'r',lw=1)
    # plt.title('Amplitude Prediction')
    
    # plt.xlabel('Y Test')
    # plt.ylabel('Predicted Y')
    # plt.show()
    
    # print('Amplitude')
    # print('MAE:', metrics.mean_absolute_error(y_test_amplitude, amplitude_predictions))
    # print('MSE:', metrics.mean_squared_error(y_test_amplitude, amplitude_predictions))
    # print('RMSE:', np.sqrt(metrics.mean_squared_error(y_test_amplitude, amplitude_predictions)))
    # print('% Error: ', 100*metrics.mean_absolute_error(y_test_amplitude, amplitude_predictions)/np.mean(y_test_amplitude))
    # print('Score:', clf3.score(X_test_scaled,amplitude_predictions),'\n')
    # # print('Coefficients: ')
    
    # # #pd.set_option('display.max_columns', df.shape[1]+1)
    # # coeffs3 = np.abs(clf3.coef_)/np.sum(np.abs(clf3.coef_))*100
    # # df = pd.DataFrame(data = coeffs3, columns = X_train_amplitude.columns.tolist())
    # # df = df.loc[0].abs().sort_values()
    # # print(df,'\n')
    
    # # #pd.set_option('display.max_columns', df.shape[1]+1)
    # # coeffs4 = np.abs(clf4.coef_)/np.sum(np.abs(clf4.coef_))*100
    # # df = pd.DataFrame(data = coeffs4, columns = X_train.columns.tolist())
    # # df = df.loc[0].abs().sort_values()
    # # print(df,'\n')
    
    X_test2 = X_test.copy() 
    X_test2['peak_velocity_predictions'] = velocity_predictions
    X_test2['duration_predictions'] = time_predictions
    # X_test2['amplitude_predictions'] = amplitude_predictions
    X_test2['mean_vel_predictions'] = mean_vel_predictions
    
    return X_train, X_train_scaled, y_train, X_test2,y_test, clf4, clf2
    
# def predict_values(dataset,clf,clf2,min_max_scaler, min_max_scaler2):
    
#     dataset2 = dataset.drop(['Peak Amplitude','Peak Velocity','Mean Velocity','Time at end'],axis=1)
    
#     scaled_velocity = min_max_scaler.transform(dataset2)
#     scaled_amplitude = min_max_scaler2.transform(dataset2)
    
#     velocity_prediction = clf.predict(scaled_velocity)
#     amplitude_prediction = clf2.predict(scaled_amplitude)
    
#     df_predictions = dataset.copy() 
    
#     df_predictions['velocity_prediction'] = velocity_prediction
#     #df_predictions['amplitude_prediction'] = amplitude_prediction
#     df_predictions['Time at end prediction'] = amplitude_prediction

#     return df_predictions

# def evaluate(df_predictions_SVM):
    
#     from sklearn import metrics
#     import seaborn as sns
#     import numpy as np
#     import matplotlib.pyplot as plt
        
#     plt.figure(figsize=(10,5))
#     plt.subplot(1,2,1)
#     plt.scatter(df_predictions_SVM['Time at end'],df_predictions_SVM['Mean Velocity'])
#     plt.scatter(df_predictions_SVM['Time at end prediction'],df_predictions_SVM['velocity_prediction'])
#     plt.xlabel('Total Trajectory Duration')
#     plt.ylabel('Mean Trajectory Velocity')
#     plt.legend(['Real','predicted'])
    
#     time_at_end_err = 100*(df_predictions_SVM['Time at end prediction']-df_predictions_SVM['Time at end'])/df_predictions_SVM['Time at end']
#     mean_velocity_err = 100*(df_predictions_SVM['velocity_prediction']-df_predictions_SVM['Mean Velocity'])/df_predictions_SVM['Mean Velocity']
    
#     plt.subplot(1,2,2)
#     plt.scatter(time_at_end_err, mean_velocity_err)
#     plt.xlabel('Total Trajectory Duration % Error')
#     plt.ylabel('Mean Trajectory Velocity % Error')
    
#     plt.show()
    
#     print('Duration:\n')
#     print('MAE:', metrics.mean_absolute_error(df_predictions_SVM['Time at end'], df_predictions_SVM['Time at end prediction']))
#     print('MSE:', metrics.mean_squared_error(df_predictions_SVM['Time at end'], df_predictions_SVM['Time at end prediction']))
#     print('RMSE:', np.sqrt(metrics.mean_squared_error(df_predictions_SVM['Time at end'], df_predictions_SVM['Time at end prediction'])))
    
#     #print(clf.score(df_predictions_SVM['Time at end'], df_predictions_SVM['Time at end prediction']))
#     #print(clf.coef_)
                
#     sns.lmplot(x= 'Time at end',y = 'Time at end prediction', data = df_predictions_SVM)
    
#     print('Mean Velocity:\n')
    
#     print('MAE:', metrics.mean_absolute_error(df_predictions_SVM['Mean Velocity'], df_predictions_SVM['velocity_prediction']))
#     print('MSE:', metrics.mean_squared_error(df_predictions_SVM['Mean Velocity'], df_predictions_SVM['velocity_prediction']))
#     print('RMSE:', np.sqrt(metrics.mean_squared_error(df_predictions_SVM['Mean Velocity'], df_predictions_SVM['velocity_prediction'])))
    
#     #print(clf.score(df_predictions_SVM['Time at end'], df_predictions_SVM['Time at end prediction']))
#     #print(clf.coef_)
                
#     sns.lmplot(x= 'Mean Velocity',y = 'velocity_prediction', data = df_predictions_SVM)
#     plt.show()
    
def mjtg(current, setpoint, frequency, move_time):
    trajectory = []
    trajectory_derivative = []
    timefreq = int(move_time * frequency)

    for time in range(1, timefreq):
        trajectory.append(
            current + (setpoint - current) *
            (10.0 * (time/timefreq)**3
             - 15.0 * (time/timefreq)**4
             + 6.0 * (time/timefreq)**5))

        trajectory_derivative.append(
            frequency * (1.0/timefreq) * (setpoint - current) *
            (30.0 * (time/timefreq)**2.0
             - 60.0 * (time/timefreq)**3.0
             + 30.0 * (time/timefreq)**4.0))

    return trajectory, trajectory_derivative

def plot_predicted_traj(df_predictions_SVM,trajectory):
    
    import numpy as np
    import matplotlib.pyplot as plt
    
    
    for segment_num in range(30,31):
    
        current = trajectory[segment_num].iloc[0,-3]
        #setpoint = df_predictions_SVM.iloc[segment_num,len(df_predictions_SVM.T)-3]*df_predictions_SVM.iloc[segment_num,len(df_predictions_SVM.T)-1]#df_predictions_SVM.iloc[segment_num,len(df_predictions_SVM.T)-1]#df_predictions_SVM.iloc[segment_num,len(df_predictions_SVM.T)-1]
        setpoint = df_predictions_SVM.iloc[segment_num,-1]*df_predictions_SVM.iloc[segment_num,-2]*2
        
        frequency = 100
        time = df_predictions_SVM.iloc[segment_num,-2]*2#(df_predictions_SVM.iloc[segment_num,len(df_predictions_SVM.T)-1]-current)/df_predictions_SVM.iloc[segment_num,len(df_predictions_SVM.T)-2]
        
        traj1, traj_vel = mjtg(current, setpoint, frequency, time)
        
        traj = np.array(traj1)
        #time_ = np.where(traj < 5)[-1][0]
        
        end_segment_point = trajectory[segment_num].iloc[0,-3]+32.0
        
        traj = traj[traj>end_segment_point]
    
        # Create plot.
        #xaxis = [i / frequency for i in range(1, int(time * frequency))]
        
        xaxis = np.linspace(0.0,6.0,601)
        
        index_ = trajectory[segment_num].loc[(trajectory[segment_num]['angular position'] > end_segment_point)].index[0]- trajectory[segment_num].index[0]
        
    #    if len(traj) > len(trajectory[segment_num]):
    #        traj = traj[0:len(trajectory[segment_num])]
    #    else:
    #        trajectory[segment_num] = trajectory[segment_num].iloc[0:len(traj)]
        
        plt.figure(1,figsize=(5,5))
        plt.plot(xaxis[index_:len(traj)+index_], traj)
        plt.plot(xaxis[0:len(trajectory[segment_num].iloc[:,-3])], trajectory[segment_num].iloc[:,-3])
        
        #plt.plot(xaxis, traj_vel)
        plt.title("Minimum jerk trajectory")
        plt.xlabel("Time [s]")
        plt.ylim(0,100)
        plt.ylabel("Angle [deg]")
        plt.legend(['Predicted', 'Real'])
        plt.savefig('predicted_and_real_traj_40%.svg', format='svg')
    #    plt.figure(2)
    #    plt.plot(trajectory[segment_num]['time'],trajectory[segment_num]['imu'])
    #    
        plt.show()


def normalise_MVC(emg_MVC, dataset):
    
    import matplotlib.pyplot as plt
    import numpy as np
    
    """
    Function to normalise EMG signals to MVC
    
    """
    
    # plt.subplot(2,2,1)
    # plt.plot(emg_MVC['Time'], emg_MVC['Biceps'])
    # plt.title('biceps')
    
    # plt.subplot(2,2,2)
    # plt.plot(emg_MVC['Time'], emg_MVC['Triceps'])
    # plt.title('triceps')
    
    # plt.subplot(2,2,3)
    # plt.plot(emg_MVC['Time'], emg_MVC['Deltoid'])
    # plt.title('Deltoid')
    
    # plt.subplot(2,2,4)
    # plt.plot(emg_MVC['Time'], emg_MVC['Pecs'])
    # plt.title('Pecs')
    
    # plt.show()
    
    
    # filter the MVC signal
    biceps_env = filteremg(emg_MVC['Time'], emg_MVC['Biceps'], graphs=0)
    triceps_env = filteremg(emg_MVC['Time'], emg_MVC['Triceps'],  graphs=0)
    deltoid_env = filteremg(emg_MVC['Time'], emg_MVC['Deltoid'],  graphs=0)
    pecs_env = filteremg(emg_MVC['Time'], emg_MVC['Pecs'], graphs=0)
    
    
    # find the maximum values (search for the biceps maximum in the first half of the signal )
    # a = int(0.5*len(biceps_env))
    biceps_MVC = np.max(biceps_env) #biceps_env[0:a]
    triceps_MVC = np.max(triceps_env)
    deltoid_MVC  = np.max(deltoid_env)
    pecs_MVC = np.max(pecs_env)
    
    # normalise the signals based on the MVC
    dataset['biceps'] = dataset['biceps']/biceps_MVC
    dataset['triceps'] = dataset['triceps']/triceps_MVC
    dataset['deltoid'] = dataset['deltoid']/deltoid_MVC
    dataset['pecs'] = dataset['pecs']/pecs_MVC
    
    return dataset

def ANN(df):
    
    from sklearn.model_selection import train_test_split
    from sklearn import metrics
    from sklearn.svm import SVR
    from sklearn import preprocessing
    from sklearn.metrics import classification_report,confusion_matrix, mean_absolute_error, mean_squared_error, explained_variance_score
    from sklearn.preprocessing import MinMaxScaler
    
    from tensorflow.keras.models import Sequential
    from tensorflow.keras.layers import Dense, Activation, Dropout
    from tensorflow.keras.optimizers import Adam
    
    import matplotlib.pyplot as plt
    import numpy as np
    import pandas as pd
    import seaborn as sns
    import sys
    
    # Define X and y
    #X = df.drop(['Peak Amplitude','Peak Velocity','Mean Velocity','Time at end', 'Time at half'],axis=1)
    features_int = ['biceps_max','biceps_sum','curr_acc','curr_velocity', 'segment_duration','triceps_min', 'curr_triceps_change2', 'pecs_sum']# 'triceps_max','pecs_sum','curr_triceps_change2'\
        
    X = df[features_int]     
    y = df[['Time at half','Mean Velocity']]
    
    # Split the data into train and test randomly with the test size = 30%
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.30, random_state=41) 
    
    # Create scalar
    scaler = MinMaxScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)
    
    # Split y 
    y_test_vel = y_test.iloc[:,1]
    y_test_time = y_test.iloc[:,0]
    
    # Create ANN Model 
    model = Sequential()
    
    model.add(Dense(8,activation='relu'))
    #model.add(Dropout(0.5))
    model.add(Dense(4,activation='relu'))

    model.add(Dense(1))
    
    model.compile(optimizer='adam',loss='mse')
    
    model.fit(x= X_train, y= y_train.values, validation_data = (X_test,y_test_vel.values),batch_size=50, epochs = 300)
    
    losses = pd.DataFrame(model.history.history)
    
    losses.plot()
    
    ## Model Evaluation
    predictions = model.predict(X_test)
    
    print(mean_absolute_error(y_test_vel,predictions))
    print(mean_squared_error(y_test_vel,predictions))
    print((explained_variance_score(y_test_vel,predictions)))
    print(df['Mean Velocity'].mean())
    
    plt.figure(2)
    # Our predictions
    plt.scatter(y_test_vel,predictions)
    
    # Perfect predictions
    plt.plot(y_test_vel, y_test_vel,'r')
    
    return 
    
    # Outlier detection 

def detect_outliers(df,n,features):
    
    """
    Takes a dataframe df of features and returns a list of the indices
    corresponding to the observations containing more than n outliers according
    to the Tukey method.
    """
    outlier_indices = []
    
    # iterate over features(columns)
    for col in features:
        # 1st quartile (25%)
        Q1 = np.percentile(df[col], 25)
        # 3rd quartile (75%)
        Q3 = np.percentile(df[col],75)
        # Interquartile range (IQR)
        IQR = Q3 - Q1
        
        # outlier step
        outlier_step = 1.5 * IQR
        
        # Determine a list of indices of outliers for feature col
        outlier_list_col = df[(df[col] < Q1 - outlier_step) | (df[col] > Q3 + outlier_step )].index
        
        # append the found outlier indices for col to the list of outlier indices 
        outlier_indices.extend(outlier_list_col)
        
    # select observations containing more than 2 outliers
    outlier_indices = Counter(outlier_indices)        
    multiple_outliers = list( k for k, v in outlier_indices.items() if v > n )
    
    return multiple_outliers 
    
def baseline_regression_models(X_train, y_train, mean_val, kfolds=0, n_jobs=1, combined = 0):
    
    classifiers = []
    classifiers.append(SVR())
    classifiers.append(DecisionTreeRegressor(random_state=42))
    classifiers.append(AdaBoostRegressor(DecisionTreeRegressor(random_state=42),random_state=42,learning_rate=0.1))
    classifiers.append(RandomForestRegressor(random_state=42))
    classifiers.append(ExtraTreesRegressor(random_state=42))
    classifiers.append(GradientBoostingRegressor(random_state=42))
    classifiers.append(MLPRegressor(random_state=42))
    classifiers.append(ElasticNet(random_state=42))
    classifiers.append(Lasso(random_state=42))
    classifiers.append(Ridge(random_state=42))
    
    if kfolds ==0:
        kfolds = KFold(n_splits=10, shuffle=True, random_state=42)
    
    cv_results = []
    for classifier in classifiers :
        cv_results.append(-cross_val_score(classifier, X_train, y_train, scoring = "neg_mean_absolute_error", cv = kfolds, n_jobs=n_jobs))
    
    cv_means = []
    cv_std = []
    for cv_result in cv_results:
        cv_means.append(cv_result.mean()*100/mean_val)
        cv_std.append(cv_result.std()*100/mean_val)
    
    cv_res = pd.DataFrame({"CrossValMeans":cv_means,"CrossValerrors": cv_std,"Algorithm":["SVR","DecisionTree","AdaBoost",
    "RandomForest","ExtraTrees","GradientBoosting","MultipleLayerPerceptron","ElasticNet","Lasso","Ridge"]})
    
    plt.figure()
    g = sns.barplot("CrossValMeans","Algorithm",data = cv_res.sort_values('CrossValMeans'), palette="Set3",orient = "h",**{'xerr':cv_std})
    g.set_xlabel("Mean Absolute Error")
    #g = g.set_title("Cross validation scores{}".format(mean_val))
    return cv_res
    # RFR = RandomForestRegressor(random_state=42)
    # RFR.fit(X_train,y_train)
    # #cross_val_error_ht.append(np.mean(-cross_val_score(baseline, X_train, y_train_mv, scoring = "neg_mean_absolute_error", cv = kfolds, n_jobs=n_jobs))*100/mean_mean_velocity)

    # predictors = list(X_train)
    # feat_imp = pd.Series(RFR.feature_importances_, predictors).sort_values(ascending=False)
    # feat_imp.plot(kind='bar', title='Importance of Features')
    
    # time_imp = 0
    # imu_imp = 0
    # stretch_imp = 0
    # emg_imp = 0
    
    # print(cv_res.sort_values('CrossValMeans').reset_index(drop=True))
    
    # if combined ==1:
    
    #     for item in feat_imp.index:
    #         #print(item)
            
    #         x = feat_imp.loc[item]
            
    #         if 'time' in item:
                
    #             time_imp = time_imp + x
                
    #         if 'pos' in item or 'vel' in item or 'acc' in item:
                
    #             imu_imp = imu_imp + x
                
    #         if 'stretch' in item:
                
    #             stretch_imp = stretch_imp + x
            
    #         if 'bb' in item or 'tb' in item  or 'ad' in item or 'pm' in item:
                
    #             emg_imp = emg_imp + x
        
    #     sensor_imp_lst = [time_imp, imu_imp, stretch_imp, emg_imp]
    
    #     sensor_imp = pd.Series(sensor_imp_lst,['time','imu','stretch','emg' ])
    
    
    #     return cv_res.sort_values('CrossValMeans').reset_index(drop=True), feat_imp, sensor_imp
    
    # return cv_res.sort_values('CrossValMeans').reset_index(drop=True), feat_imp
    
    
def baseline_classification_models(X_train, y_train, mean_val=100, kfolds=0):
    classifiers = []
    classifiers.append(SVC())
    classifiers.append(DecisionTreeClassifier(random_state=42))
    classifiers.append(ExtraTreeClassifier(random_state=42))
    classifiers.append(GradientBoostingClassifier(random_state=42))
    classifiers.append(RandomForestClassifier(random_state=42))
    #classifiers.append(KNeighborsClassifier())
    #classifiers.append(RadiusNeighborsClassifier())
    classifiers.append(MLPClassifier(random_state=42))
    classifiers.append(SGDClassifier(random_state=42))
    classifiers.append(LogisticRegression(random_state=42))
    classifiers.append(RidgeClassifierCV())

    if kfolds ==0:
        kfolds = KFold(n_splits=10, shuffle=True, random_state=42)
        
    cv_results = []
    for classifier in classifiers :
        cv_results.append(cross_val_score(classifier, X_train, y_train, scoring = "accuracy", cv = kfolds))

    cv_means = []
    cv_std = []
    for cv_result in cv_results:
        cv_means.append(cv_result.mean()*100/mean_val)
        cv_std.append(cv_result.std()*100/mean_val)
    
    cv_res = pd.DataFrame({"CrossValMeans":cv_means,"CrossValerrors": cv_std,"Algorithm":["SVC","DecisionTree","ExtraTree",
    "GradientBoosting","RandomForest", "MultipleLayerPerceptron","SGD","Logistic","Ridge"]})
    
    return cv_results, cv_res


# class RNN():
#     import numpy as np
#     import tensorflow as tf
#     from tensorflow import keras
#     from tensorflow.keras import layers 
#     def 
    
































    
    
    
    
    
    