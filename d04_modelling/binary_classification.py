# -*- coding: utf-8 -*-
"""
Created on Wed Mar 10 15:28:34 2021

@author: sibo0
"""
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.io
import pickle
import seaborn as sns   

from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.svm import SVR
from src.d00_utils.functions import *
from scipy import stats
from sklearn.metrics import confusion_matrix, classification_report,accuracy_score
from sklearn.preprocessing import StandardScaler,LabelEncoder
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeRegressor
from sklearn.neural_network import MLPRegressor
from sklearn.svm import SVC
from sklearn.linear_model import SGDClassifier
from sklearn.model_selection import GridSearchCV, cross_val_score, StratifiedKFold, learning_curve, KFold
from sklearn.linear_model import ElasticNetCV, LassoCV, RidgeCV, Ridge, ElasticNet, Lasso
from sklearn.multiclass import OneVsOneClassifier, OneVsRestClassifier
#%%
new_windows = windows.loc[windows['position_num'] == 1]

new_windows = new_windows.append(windows.loc[windows['position_num'] == 5])

X_org = new_windows.drop(['time','segment_RP','position_num'],axis=1)
y = new_windows.loc[:,'position_num']

X_train1, X_test1, y_train1, y_test1 = train_test_split(X_org, y, test_size=0.30, random_state=42)

# scalling the features
le = LabelEncoder()
sc = StandardScaler()
X_train1 = sc.fit_transform(X_train1)
X_test1 = sc.transform(X_test1)
y_train1 = le.fit_transform(y_train1)
y_test1 = le.fit_transform(y_test1)
#%%
# bins = 2
# new_windows['position_num'] = pd.cut(new_windows['position_num'], bins)
# new_windows['position_num'].unique()
rfc = RandomForestClassifier(n_estimators=150)
rfc.fit(X_train1, y_train1)
pred_rfc = rfc.predict(X_test1)
df_predictions1 = pd.DataFrame({'y_test':y_test1, 'predictions':pred_rfc})
print(accuracy_score(y_test1, pred_rfc))