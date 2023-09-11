import gym
import time
import numpy as np
import pandas as pd
import torch
from Model import PolicyNet


# This class is to interact with the environment
class EnvAdapterForLunarLander:
    def __init__(self):
        self._env = gym.make("LunarLander-v2")  # This is the environment
        self.observation = (
            self._env.reset()
        )  # This is the init observation of the environment
        self.titles = {
            "observation": [],
            "reward": [],
            "action": [],
        }  # This is the titles of the RunData.csv
        self.policy_net = (
            PolicyNet()
        )  # This is the policy network and loading its parameters
        self.policy_net.load_state_dict(torch.load("./Parameters/PolicyNet.pt"))
        self.policy_net.eval()

    # This function is to initialize the title of the RunData.csv
    def initRunData(self):
        df = pd.DataFrame(self.titles)  # Create a dataframe
        df.to_csv("RunData.csv", index=False)  # Save the dataframe to RunData.csv

    # This function is to run one step of the environment
    def runStep(self, video):
        action = self.policy_net.actionSelector(
            self.policy_net(self.policy_net.formInput(self.observation))
        )  # run the forward function of the policy network to get the action
        observation_next, reward, done, info = self._env.step(
            action
        )  # interact with the environment
        rowdata = {
            "observation": [np.array(self.observation)],
            "reward": [np.array(reward)],
            "action": [np.array(action)],
        }  # obtain the row data of the observation, reward and action
        self.observation = (
            observation_next  # update the observation (statement transition)
        )
        df = pd.DataFrame(rowdata)
        df.to_csv(
            "RunData.csv", mode="a", header=False, index=False
        )  # save the row data to RunData.csv

        if video:
            self._env.render()  # render the environment
            time.sleep(0.01)  # pause 0.01 second
            # print(self.policy_net(self.policy_net.formInput(self.observation)))
        return done

    def closeEnv(self) :
        self._env.close()