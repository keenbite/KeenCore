# 🌀 KeenCore – The Future of WoW Server Emulation

**KeenCore** is a modern, modular, and multiversion-capable World of Warcraft server core – built for enthusiasts, developers, and pioneers of the private server scene.  
Based on the time-tested foundation of **MaNGOS**, KeenCore sets its sights higher:  
🚀 *One server to run them all – Classic to Retail. Simple. Flexible. Future-ready.*

---

![C++](https://img.shields.io/badge/-C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![MySQL](https://img.shields.io/badge/MySQL-4479A1?style=flat&logo=mysql&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-064F8C?style=flat&logo=cmake&logoColor=white)
![License](https://img.shields.io/badge/License-GPL%20v2-blue.svg)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)

---

## 🌍 What is KeenCore?

**KeenCore** is more than just another fork – it’s a vision:  
A single server system capable of running multiple major versions of World of Warcraft under one unified architecture – from **Vanilla** to **Shadowlands** (and beyond in the future).

It inherits the legacy of **MaNGOS ZERO**, while introducing a modernized architecture, cleaner codebase, and powerful developer tooling.  
Our goal is to build a platform that honors the past, embraces the present, and adapts to the future.

---

## 🛠️ Key Features

### 🔄 Multiversion Support *(Work in Progress)*
- ✅ Classic (1.12.x)
- 🚧 TBC / and all versions beyond (experimental)
- 🧪 Retail-ready foundations (future-facing)

### 🧱 Modern Core Architecture
- Fully modular: swap or extend components like Auth, Maps, AI
- Clean C++17/20+ codebase
- Clear server structure: `authserver`, `worldserver`, `dbcore`, `tools`, etc.

### 🧠 Developer-Centric
- Intuitive project structure
- Simple build system using CMake
- Extensive logging and debugging support
- Documentation-first philosophy

### 💾 Database-Focused Design
- Performance-optimized schema
- Planned support for REST APIs and Web Interfaces
- Migration tools between client versions (future)

---

## 📦 Quick Start

> KeenCore is in active development. Many systems are still under construction.

### 1. Requirements

- Git
- CMake (>= 3.12)
- C++17-compatible compiler (GCC, Clang, MSVC)
- MySQL / MariaDB
- *(Optional)* vcpkg for dependency management

### 2. Clone the repository

```bash
git clone https://github.com/keenbite/server.git
cd server
```

### 3. Build the project

```bash
cmake -B build -S .
cmake --build build
```

### 4. Setup the database

```bash
# Example: Classic DB import
mysql -u root -p < sql/Classic/full_db.sql
```

### 5. Configuration

Edit config files in the configs/ folder to match your local setup.

### 📚 Documentation
The full documentation is under active development.
In the meantime, check the Wiki or browse the docs/ folder.

### 🤝 Contributing
KeenCore is an open-source community project.
We welcome contributions in all forms – code, feedback, bug reports, testing across WoW versions, or even helping write documentation.


### 📬 Pull Requests and Issues are always welcome!


### 🧬 Legacy and Philosophy
KeenCore is built on the shoulders of giants.
It is based on the MaNGOS ZERO Core – one of the most respected and time-proven open-source WoW server projects.

We honor that legacy while reimagining what a modern, multi-version, developer-friendly WoW server platform can be.

### 📄 License
KeenCore is licensed under the GNU GPL v2.0.
See LICENSE for details.

## 🧭 Roadmap (Highlights)

- ✅ Classic 1.12.x support
- 🚧 TBC in progress
- 🔧 Modular core & tools
- 🌐 Planned: Web UI & REST API
- 🧪 Long-term: multi-version launcher

### KeenCore – Build your world. Across all versions.
