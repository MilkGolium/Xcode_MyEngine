# Soft2D

Soft2D is a **deterministic 2D runtime** for building **reproducible, replayable, and verifiable**
interactive simulations and games.

It is designed for systems where **correctness, consistency, and explainability**
matter more than visual fidelity or raw rendering performance.

---

## Why Soft2D?

Modern game engines and simulation frameworks often sacrifice determinism for
performance, parallelism, or convenience.  
This leads to problems such as:

- Bugs that cannot be reliably reproduced
- Desynchronization between clients
- Non-identical replays on different machines
- Heisenbugs caused by timing, floating-point, or platform differences

Soft2D takes the opposite approach.

> **If the same initial state and the same inputs are provided,  
> the simulation will always follow the exact same trajectory.**

No ghost movement.  
No divergent replays.  
No "it only happens on my machine".

---

## Core Principles

Soft2D is built on several strict principles:

- **Deterministic simulation**
  - Fixed-step update
  - Controlled time progression
  - Explicit randomness

- **Replay-first architecture**
  - Input is data, not events
  - Record once, replay anywhere
  - Replay drives the simulation, not rendering

- **Pure software rendering**
  - No GPU, no shaders
  - Predictable execution
  - Identical results across platforms

- **Explainable system behavior**
  - Clear module boundaries
  - Verifiable state transitions
  - Designed for debugging and validation

---

## What Soft2D Is *Not*

Soft2D intentionally does **not** try to be:

- A high-performance GPU renderer
- A feature-complete game engine
- A visual effects framework
- A "one-size-fits-all" solution

This project values **trustworthiness over completeness**.

---

## Intended Use Cases

Soft2D is suitable for:

### 1. Education & Research
- Teaching game loops, simulation, and time systems
- Demonstrating deterministic vs non-deterministic behavior
- Physics, AI, or system modeling without hidden magic

### 2. Simulation & Verification
- Traffic or crowd simulations
- AI training environments
- Automated testing with replayable scenarios

### 3. Internal Tools for Game Development
- Reproducible bug reports
- Deterministic replays for QA
- Debugging rare or timing-dependent issues

---

## Architecture Overview

Soft2D is organized into decoupled modules:

- `platform` — windowing and platform abstraction
- `draw` — pure framebuffer-based software rendering
- `time` — fixed-step simulation timing
- `input` — deterministic input state collection
- `simulation` — world state update logic
- `replay` — input recording and playback

Rendering is a **pure function of world state** and never mutates simulation data.

---

## Determinism Guarantees

Soft2D aims to provide:

- Identical simulation results on the same platform
- Deterministic behavior under controlled numeric rules
- Replay consistency across runs

Limitations and non-guarantees are documented explicitly in `DESIGN.md`.

---

## Platform Support

Currently tested on:

- macOS 26.2 (Xcode 26.2, clang)

Other platforms are planned, but not yet validated.

---

## Project Status

Soft2D is currently **experimental** and under active development.

APIs may change.

---

## License

[GPL-3.0](https://www.gnu.org/licenses/gpl-3.0.txt)
