🌌 3D Solar System Simulation

A 3D Solar System simulation written in C using raylib, built to visualize fundamental concepts of astrophysics and space dynamics.
This project demonstrates how celestial bodies move under the influence of gravity, and introduces ideas inspired by Newton’s law of universal gravitation and Einstein’s special relativity (النسبية الخاصة).

🧠 Overview

This simulation models the motion of celestial bodies in a simplified 3D environment.
It aims to illustrate how:

Objects orbit due to gravitational attraction between masses (Newtonian physics).

Time and motion are relative to the observer’s frame of reference, inspired by Einstein’s special relativity.

Position, velocity, and rotation can be visualized dynamically in real-time.

⚛️ Core Concepts
🔭 Newton’s Law of Universal Gravitation

Each celestial body experiences a force proportional to the product of their masses and inversely proportional to the square of their distance:

𝐹=𝐺𝑚1𝑚2𝑟^2

This fundamental law governs the orbits and relative motions between the objects in the simulation.

🕰️ Einstein’s Special Relativity

While the simulation doesn’t implement full relativistic physics, it draws conceptual inspiration from Einstein’s insights about:

The relativity of time and motion

Speed limits in the universe (the speed of light, 
𝑐
c)

The connection between energy and mass: 
𝐸
=
𝑚
𝑐
2
E=mc
2

These ideas inform the design philosophy — that observation and reference frames matter even in a simplified model.

⚙️ Requirements

C compiler (GCC / Clang / MSVC)

Build : 
use 'gcc main.c elements.c elements.h -o Emulator -lraylib -lm'
