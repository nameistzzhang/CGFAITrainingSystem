from EnvAdapter import EnvAdapterForLunarLander
from PolicyGradient import PolicyGradient
from Model import PolicyNet
import time


# This class is to manage the training process
class TrainManager:
    def __init__(self) -> None:
        pass

    # This function is to run the parameters and form a game data
    def interactEnv(self, video):
        env_adapter = EnvAdapterForLunarLander()

        env_adapter.initRunData()

        while 1:
            done = env_adapter.runStep(video)
            if done:
                env_adapter.closeEnv()
                break

    def runPolicyGradient(self, epoch_):
        
        policy_gradient = PolicyGradient()

        policy_gradient.loadGameInfo()

        loss, even_reward = policy_gradient.learn()

        

        print("Epoch: ", epoch_, " Loss: ", loss, " Reward: ", even_reward)


    def newTrain(self) :

        policy_net = PolicyNet()
        policy_net.saveNewParam()