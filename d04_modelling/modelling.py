# -*- coding: utf-8 -*-
"""
Created on Mon Mar  8 15:46:07 2021

@author: sibo0
"""
### Imports

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.io
import pickle
import seaborn as sns   

from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error
from sklearn.svm import SVR
from src.d00_utils.functions import *
from scipy import stats
from sklearn.metrics import confusion_matrix, classification_report,accuracy_score
from sklearn.preprocessing import StandardScaler,LabelEncoder
from sklearn.ensemble import RandomForestRegressor, AdaBoostRegressor, GradientBoostingRegressor, ExtraTreesRegressor, VotingRegressor, RandomForestClassifier, GradientBoostingClassifier
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

import sys
import os
import pickle
#%% Split the training set and testing set
# drop the data from 6th position
# indexNames = windows[windows['position_num'] == 6].index
# windows.drop(indexNames,inplace = True)

X_org = windows.drop(['time','segment_RP','position_num'],axis=1)
y = windows.loc[:,'position_num']

# drop the 6th position in the training set; only use 6th position to test

# X_org = windows.drop(['time','segment_RP','position_num'],axis=1)
# y = windows.loc[:,'position_num']
# X_train = X_org
# y_train = y
# X_test = window_seg[5]
# X_test = X_test.drop(['time','segment_RP','position_num'],axis=1)
# y_test = window_seg[5]['position_num']


#%%
X_train, X_test, y_train, y_test = train_test_split(X_org, y, test_size=0.30, random_state=42)

# scalling the features

sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
#%% Test model using single dataset (baseline_classification_models)
mean_val = 100
cv_results, cv_res = baseline_classification_models(X_train, y_train, mean_val, kfolds = 0)
#%% Test model using regression models
mean_val = 100
cv_res = baseline_regression_models(X_test, y_test, mean_val, kfolds = 0)

#%% Stochastic gradient descent classification
sgdc = SGDClassifier(loss='log')
sgdc.fit(X_train,y_train)
pred_sgdc = sgdc.predict(X_test)
df_predictions = pd.DataFrame({'y_test':y_test, 'predictions':pred_sgdc})
#%% ovo classifier
ovo_clf = OneVsOneClassifier(SVC())
ovo_clf.fit(X_train,y_train)
pred_sgdc = sgdc.predict(X_test)
df_predictions = pd.DataFrame({'y_test':y_test, 'predictions':pred_sgdc})
# model accuracy for X_test   
accuracy = svm_model_linear.score(X_test, y_test) 
print(accuracy)
# creating a confusion matrix 
cm = confusion_matrix(y_test, svm_predictions)
print(cm)

#%% Naive bayies
# importing necessary libraries  
# training a Naive Bayes classifier 
from sklearn.naive_bayes import GaussianNB 
gnb = GaussianNB().fit(X_train, y_train) 
gnb_predictions = gnb.predict(X_test) 
  
# accuracy on X_test 
accuracy = gnb.score(X_test, y_test) 
print (accuracy) 
  
# creating a confusion matrix 
cm = confusion_matrix(y_test, gnb_predictions) 
#%% Random forest classifier
rfc = RandomForestClassifier(n_estimators=150)
rfc.fit(X_train, y_train)
pred_rfc = rfc.predict(X_test)
df_predictions = pd.DataFrame({'y_test':y_test, 'predictions':pred_rfc})
print(accuracy_score(y_test, pred_rfc))

#%% SVM classifier
# training a linear SVM classifier 
from sklearn.svm import SVC 
svm_model_linear = SVC(kernel = 'linear', C = 1).fit(X_train, y_train) 
svm_predictions = svm_model_linear.predict(X_test) 
  
# model accuracy for X_test   
accuracy = svm_model_linear.score(X_test, y_test) 
print(accuracy)
# creating a confusion matrix 
cm = confusion_matrix(y_test, svm_predictions)
print(cm)
#%% Multiple Layer Perceptron
from sklearn.model_selection import GridSearchCV 

parameter_space = {
    'hidden_layer_sizes': [20,40,50,60,70],
    'activation': ['relu','tanh'],
    'solver': ['sgd', 'adam'],
    'alpha': [0.0001, 0.005],
    'learning_rate': ['constant','adaptive'], 
    'random_state':[42]
}

MLPR = MLPRegressor()
kfolds = 10
MLPR = GridSearchCV(MLPR, parameter_space, n_jobs=-1, cv=kfolds, scoring = "neg_mean_absolute_error")
MLPR.fit(X_train, y_train)

print("The best value of MLP is: ",MLPR.best_params_)
print("Score: " ,-MLPR.best_score_)


y = y_test
a = np.min(y)
b = np.max(y)


plt.scatter(y_test,MLPR.predict(X_test))
#plt.plot([i for i in range(0.5,2.5)],[i for i in range(0.5,2.5)],'r')
#%% Adaboost and svm regression
# from sklearn.svm import SVR
ADAB = AdaBoostRegressor(DecisionTreeRegressor(random_state=42),n_estimators = 30, random_state=42,learning_rate=0.1)
ADAB.fit(X_train, y_train)


# SVR = SVR()
# SVR.fit(X_train, y_train)

Esti_w = pd.DataFrame({'estimator weights':ADAB.estimator_weights_})
Esti_w['number of estimators'] = Esti_w.index
Esti_w = Esti_w[['number of estimators','estimator weights']]
feature_imp = pd.DataFrame({'feature names': X_org.columns, 'feature importance': ADAB.feature_importances_})

f1 = plt.figure(1)
plt.subplot(2, 1, 1)
plt.scatter(y_test, ADAB.predict(X_test))
plt.title('Adaboost')
# plt.subplot(2, 1, 2)
# plt.scatter(y_test, SVR.predict(X_test))
# plt.title('SVR')

f2 = plt.figure(2)
plt.subplot(2, 1, 1)
sns.set_theme(style="whitegrid")
ax = sns.barplot(x = 'feature importance', y = 'feature names', data=feature_imp, color = 'b')
plt.title('Feature importances of Adaboost')

# f3 = plt.figure(3)
plt.subplot(2, 1, 2)
sns.set_theme(style="whitegrid")
ax1 = sns.barplot(x = 'number of estimators', y = 'estimator weights', data= Esti_w, color = 'r')
plt.title('Estimator weights of Adaboost')

plt.show()

#%% simple RNN 
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers

RNN_df = subsegments.copy()
for 