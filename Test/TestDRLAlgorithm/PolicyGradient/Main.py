from TrainManager import TrainManager
import time

train_manager = TrainManager()
# train_manager.newTrain()

video = False

for i in range(1000):
    if i % 1== 0:
        video = True

    train_manager.interactEnv(video)
    train_manager.runPolicyGradient(i)
    video = False

video = True
train_manager.interactEnv(video)
