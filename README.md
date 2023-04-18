# Miko (Shivang Vijay, shivangvijay@gmail.com)

![Alt text](miko.png)


## Compilling Instructions

Run in terminal
````
$ git clone https://gitlab.com/shivangvijay/miko.git
````

- If docker and docker-compose install in the system just you need to run one command:- 

````
$ cd miko
$ docker-compose up --build
````

- If docker and docker-compose not install, install by mentioned steps available in later part of this file.

- If don't want to install or use the docker, follow below commands:-

````
$ cd miko
$ mkdir build && cd build
$ cmake ..
$ make
$ ./Explore
````

**Note-** I optimize the docker image by 2 step build, Check the size of docker image (miko:1.0.0) using ```` $ docker images ````, It is just ~12.2 MB.

## Install Docker:-

Open Terminal and run the following commands:-

````
$ sudo apt-get update
$ sudo apt-get install curl
$ curl -fsSL https://get.docker.com/ | sh
````
Optional command:- To run docker commands without sudo 
````
$ sudo usermod -aG docker <system_username>
````
The above command add the system username in the docker group, Restart the system to complete the process. 

After restart run 

```` 
$ sudo service docker start 
````

## Install Docker Compose

Run the following commands in terminal:- 

````
$ sudo curl -L https://github.com/docker/compose/releases/download/1.29.2/docker-compose-`uname -s`-`uname -m` -o /usr/local/bin/docker-compose
$ sudo chmod +x /usr/local/bin/docker-compose
````

## Approch and Assumptions:-

- The robot can only explore in rectangular workspace [(-1,-1); (-1,1); (1,1); (1,-1)]. Other space is Non-Traversable.
- The robot exploration start at (-1,-1) and ends at (1,1)
- If robot unable to reach at end(1,1), then robot fail to explore the workspace.
- I take a step size of 0.1 in both x and y directions. 
- By considering above point make a grid of 21 Rows and 21 Columns.
- Robot can move in 8 direction (North, South, East, West, North-East, North-West, South-East, South-West)
- Done transformation from old co-ordinated system (User-facing) to new co-ordinates system (for calculation and algorithm implementation)
- Use A* search to explore (-1,-1) to (1,1)
- User can change obstacle (center co-ordinates and diameter) in main.py file. (take input in old co-ordinate system only)
- Console prints of obstacle and Path details. (In old co-ordinate system)


**Note-** I am using "Old co-ordinate", it is same which is mentioned in problem statement (-1,1)-->(1,1). <br />
          "New co-ordinate system " is tranlated, rotated and scaled with old one. I used for implementation of A*.


## Documentation

- Documentation generator using Doxygen tool.
- Go to miko/docs/html and open index.html in browser to view the documentation.
- Main page is this README.md only.

**Note-** Video is available (miko.mp4) to show how to compile and run.