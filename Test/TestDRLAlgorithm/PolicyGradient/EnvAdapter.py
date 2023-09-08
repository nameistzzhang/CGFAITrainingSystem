import gym
import time
import numpy as np
import pandas as pd

env = gym.make('LunarLander-v2')

# Initiliaze the environment

observation = env.reset()

titles = {
    'observation' : [], 
    'reward' : [],
    'done' : [],
    'info' : []
}

# put the titles into the RunData.csv

df = pd.DataFrame(titles)
df.to_csv('RunData.csv', index=False)

for i in range(1) :

    # sample a random action from the environment's action space

    random_action = env.action_space.sample()

    # get the info from the environment after taking a step with the sampled action

    observation1, reward, done, info = env.step(random_action)

    # form a row of data to be put into the RunData.csv

    rowdata = {
        'observation' : [np.array(observation)],
        'reward' : [np.array(reward)],
        'done' : [done],
        'info' : [info]
    }

    observation = observation1

    # add the row of data into the RunData.csv

    time.sleep(0.01)

    df = pd.DataFrame(rowdata)
    df.to_csv('RunData.csv', mode='a', header=False, index=False)

    if done :
        observation = env.reset()

env.close()

df_input = pd.read_csv('RunData.csv')