noOfprocesses=input("Enter number of Processes:")
index=0
n=0
i=1
burstTime=[]
arrivalTime=[]
startTime=[]
finishTime=[]
waitingTime=[]
turnaroundTime=[]

for index in range (int(noOfprocesses)):
  print("Enter Arrival Time for process",i,":")
  n=(input())
  arrivalTime.append(n)
  i=i+1
i=1
for index in range (int(noOfprocesses)):
  print("Enter Burst Time for Process",i,":")
  n=(input())
  burstTime.append(n)
  i=i+1

for index in range (int(noOfprocesses)):
  turnaroundTime.append(0)
  finishTime.append(0)
  waitingTime.append(0)

print("Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time")

temp=1
startTime=int(arrivalTime[0])
for index in range (int(noOfprocesses)):
  waitingTime[index]=startTime-int(arrivalTime[index])
  temp=temp+int(burstTime[index])
  finishTime[index]=temp
  startTime=temp
  turnaroundTime[index]=finishTime[index]-int(arrivalTime[index])
  print(" ",arrivalTime[index],' \t\t ',burstTime[index],'\t\t ',waitingTime[index],'\t\t ',turnaroundTime[index])
sumT=0 
sumW=0
for index in range(int(noOfprocesses)):
   sumT=sumT+int(turnaroundTime[index])
   sumW=sumW+int(waitingTime[index])
averageT=sumT/int(noOfprocesses)
averageW=sumW/int(noOfprocesses)
print("Average Turnaround Time = ",averageT)
print("Average Waiting Time = ",averageW)
