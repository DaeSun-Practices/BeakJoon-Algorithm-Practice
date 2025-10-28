import requests
import pandas as pd
import numpy as np
import operator
import json

BASE_URL = "https://7zszxecwra.execute-api.ap-northeast-2.amazonaws.com/api/"

class Scenario():
    def __init__ (self, problem_num):
        self.problem_num = problem_num
        header = {
            'X-Auth-Token' : 'bf9105602703003d1e5c8bd1',
            'Content-Type' : 'application/json'
        }
        data = {
            "problem": problem_num
        }

        res = requests.post(BASE_URL+'/start', headers=header, json=data).json()

        self.auth_key = res['auth_key']



    def new_requests(self):
        header = {
            'Authorization' : self.auth_key,
            'Content-Type' : 'application/json'
        }


        res = requests.get(BASE_URL+'/new_requests', headers=header).json()

        return res['reservations_info']

    def reply(self, replies):
        header = {
            'Authorization' : self.auth_key,
            'Content-Type' : 'application/json'
        }

        print(replies)

        data = {
            'replies' : replies
        }


        res = requests.put(BASE_URL+'/reply', headers=header, json=data).json()

        return res

class MotelManager():
    def __init__ (self, scene_name):
        if scene_name == 1:
            hotel_reservation = dict()
            for i in (1, 4):
                for j in (1, 21):
                    hotel_name = i * 1000 + j
                    hotel_reservation[hotel_name] = list()
            
            self.hotel_reservation = hotel_reservation
    
    


if __name__ == '__main__':
    scene = Scenario(1)
    #hotel_horizon = np.full((4, 21, 201), True, dtype=bool)
    
    for day in range(1, 201):
        asks = scene.new_requests() 
        replies = list()

        asks = reversed(sorted(asks, key=operator.itemgetter('amount')))

        for ask in asks:
            print(ask)

            replies.append({'id':ask['id'], 'reply': "accepted"})
        
        scene.reply(replies)
        
    

    print()