# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY lab5.c .
# Compile the C program
RUN gcc -o lab5 lab5.c
# Set the command to run when the container starts
CMD ["lab5"]