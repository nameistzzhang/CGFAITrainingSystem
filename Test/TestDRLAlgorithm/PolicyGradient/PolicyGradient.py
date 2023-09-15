from Model import PolicyNet
import Utilise

import torch
import torch.optim as optim
import pandas
from collections import deque
import time
import numpy as np

# Hyper parameters

GAMMA = 0.9
LR = 0.01

class PolicyGradient :

    def __init__(self) :

        # establish the game info

        self._state_list = []
        self._action_list = []
        self._reward_list = deque()
        self._return_list = deque()
        self._total_reward = 0

        # load the policy network

        self._policy_net = PolicyNet()

        self._policy_net.load_state_dict(torch.load("./Parameters/PolicyNet.pt"))
        self._policy_net.eval()

    # This function is to load the game info from the csv file
    def loadGameInfo(self) :

        game_info = pandas.read_csv("RunData.csv")

        # load the state_list

        state_list = game_info['observation'].tolist() # to a list of strings
        for i in state_list :
            cur_state = Utilise.convertToFloat(i)
            self._state_list.append(cur_state)

        # load the action_list
        action_list = game_info['action'].tolist() # to a list of strings
        for i in action_list :
            cur_action = int(i)
            self._action_list.append(cur_action)

        # load the reward_list
        reward_list = game_info['reward'].tolist() # to a list of strings
        # establish the return_list
        cur_return = 0
        for i in reward_list[::-1] :
            i = float(i)
            if i < -10 :
                i /= -10
            self._reward_list.appendleft(i)
            self._total_reward += i
            cur_return = i + GAMMA * cur_return
            self._return_list.appendleft(cur_return)

        self._return_list = np.array(self._return_list)

    
    # Based on the Info refresh the policy network
    def learn(self, w_print) :

        loss = 0
        cur_output = 0
        
        # baseline is the total return divided by the standard deviation
        baseline = self._return_list.sum() / (len(self._return_list))

        for i in range(len(self._state_list)) :

            # forward
            cur_output = self._policy_net.forward(self._policy_net.formInput(self._state_list[i]), w_print)

            # probability of the action
            cur_action_prob = cur_output[0][self._action_list[i]]

            # loss function
            cur_loss = - torch.log(cur_action_prob) * (self._return_list[i])

            loss += cur_loss

        # backward

        loss /= len(self._state_list)

        optimizer = optim.Adam(self._policy_net.parameters(), lr=LR)
        optimizer.zero_grad()
        loss.backward()

        if (w_print):
            print("gradient", self._policy_net.fc4.weight.grad)
            a = input()

        optimizer.step()

        self._policy_net.saveNewParam()

        return loss, self._total_reward