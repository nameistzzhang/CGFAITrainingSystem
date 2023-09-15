from TrainManager import TrainManager
import time

train_manager = TrainManager()
train_manager.newTrain()

video = False

for i in range(10000):
    if i % 50 == 0:
        video = True

    train_manager.interactEnv(video)
    train_manager.runPolicyGradient(i, video)
    video = False