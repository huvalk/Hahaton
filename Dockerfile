FROM opencvcourses/opencv-docker:latest

USER root

COPY . /home/Hahaton

WORKDIR /home/Hahaton
	
RUN mkdir build && \
	cmake -S . -B build && \
	cmake --build build
	
WORKDIR /home/Hahaton/build/app

CMD ./main
