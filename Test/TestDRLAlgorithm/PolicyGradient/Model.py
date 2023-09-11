import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np

Input_Size = 8
Output_Size = 4


# This class is to define the policy network
class PolicyNet(nn.Module):
    def __init__(self):
        super(PolicyNet, self).__init__()
        self.input_size = Input_Size
        self.output_size = Output_Size  # Hyperparameters

        self.fc1 = nn.Linear(self.input_size, 16)  # Two Linear layers
        self.fc2 = nn.Linear(16, 32)
        self.fc3 = nn.Linear(32, 64)
        self.fc4 = nn.Linear(64, 32)
        self.fc5 = nn.Linear(32, self.output_size)
        # self.fc4 = nn.Conv1d(  # Two Convolutional layers
        #     in_channels=1,
        #     out_channels=4,
        #     kernel_size=3,
        #     stride=1,
        #     padding=1,
        #     padding_mode="zeros",
        # )
        # self.fc5 = nn.Conv1d(
        #     in_channels=4,
        #     out_channels=8,
        #     kernel_size=3,
        #     stride=1,
        #     padding=1,
        #     padding_mode="zeros",
        # )
        # self.fc6 = nn.Conv1d(
        #     in_channels=8,
        #     out_channels=16,
        #     kernel_size=3,
        #     stride=1,
        #     padding=1,
        #     padding_mode="zeros",
        # )
        # self.fc7 = nn.Linear(16 * 128, 1000)  # Two Linear layers
        # self.fc8 = nn.Linear(1000, 100)
        # self.fc9 = nn.Linear(100, self.output_size)

    # Convert the input list to a tensor
    def formInput(self, input_list_):
        input_tensor = torch.tensor(input_list_)
        input_tensor = input_tensor.view(1, self.input_size)
        return input_tensor

    # The forward function
    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = F.relu(self.fc3(x))
        x = F.relu(self.fc4(x))
        x = F.relu(self.fc5(x))
        # x = self.fc4(x)
        # x = self.fc5(x)
        # x = self.fc6(x)
        # x = x.view(-1, 16 * 128)
        # x = F.relu(self.fc7(x))
        # x = F.relu(self.fc8(x))
        # x = F.relu(self.fc9(x))
        # print("before softmax : ", x)
        x = F.softmax(x)
        return x

    # select action according to the output of the policy network
    def actionSelector(self, output):
        # select the action according to the probability

        probability = output.reshape(4)

        action = np.array([0, 1, 2, 3])
        action = np.random.choice(action, p=probability.detach().numpy())

        return action
    
    # save a brand new parameter
    def saveNewParam(self) :
        torch.save(self.state_dict(), "./Parameters/PolicyNet.pt")
