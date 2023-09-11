from TrainManager import TrainManager
import time

train_manager = TrainManager()

video = False

for i in range(10000):
    if i % 100== 0:
        video = True

    train_manager.interactEnv(video)
    train_manager.runPolicyGradient(i)
    video = False