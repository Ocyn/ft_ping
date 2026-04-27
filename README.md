# 🔍 **Ft_Ping** – *A 42 School Didactic Project*

**Recode the `ping` command to explore TCP/IP networking fundamentals between two machines.**
This project is part of the **42 School curriculum** (Networking track) and serves as a hands-on introduction to packet transmission, latency, and basic network diagnostics.

---

## 📌 **Project Overview**
A lightweight modification of the standard `ping` utility to demonstrate:
- **ICMP protocol** (Internet Control Message Protocol)
- **ARP resolution** (Address Resolution Protocol)
- **Network latency & packet loss** visualization
- **Basic TCP/IP stack** interactions

**Goal:** Understand how network communication works at the lowest level, from packet crafting to response handling.

---

## 🛠 **Features**
- ✅ **Customizable ping packets** (TTL, payload, timestamps)
- ✅ **Real-time latency & loss statistics**
- ✅ **Cross-platform compatibility** (Linux/Unix environments)
- ✅ **Minimal dependencies** (pure C, no external libraries)
- ✅ **42 School-compliant** (follows project norms & submission rules)

---

## 🎓 **Why This Project?**
This is a **mandatory didactic project** for **42 School students** in the **Networking specialization**.
It reinforces:
- **Low-level networking concepts** (sockets, protocols, routing)
- **Debugging & troubleshooting** skills
- **Code optimization** (efficient packet handling)

> *"The best way to learn networking is by breaking and rebuilding it yourself."*
> — **42 Networking Curriculum**

---

## 📂 **Repository Structure**
```
ft_ping/
├── src/               # Main source code (C)
│   ├── ping.c         # Core ping logic
│   ├── utils.c        # Helper functions
│   └── Makefile       # Compilation rules
├── tests/             # Unit & integration tests
├── docs/              # Technical documentation
│   └── protocol.md    # ICMP/ARP deep dive
└── README.md          # You're here!
```

---

## 🚀 **How to Use**
### **1. Clone & Build**
```bash
git clone https://github.com/Ocyn/ft_ping
cd ft_ping
make
```

### **2. Run the Custom Ping**
```bash
./ping <target_IP> [options]
```
**Example:**
```bash
./ping 192.168.1.1 -c 4 -t 0.5
```
- `-c 4` → Send 4 packets
- `-t 0.5` → Timeout of 0.5 seconds

### **3. Compare with Standard Ping**
```bash
# Standard Linux ping
ping -c 4 192.168.1.1

# Your custom version
./ping 192.168.1.1 -c 4
```

---

## 📚 **Learning Resources**
- **[ICMP Protocol RFC 792](https://tools.ietf.org/html/rfc792)** (Official spec)
- **[42 Networking Norms](https://github.com/42School/networking-norms)** (Project rules)
- **[Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/)** (Sockets tutorial)

---

## 🤝 **Contributing**
This is a **42 School project**, so contributions are restricted to:
- **Bug fixes** (if you find edge cases)
- **Documentation improvements** (add more explanations)
- **Optimizations** (but must comply with 42 norms)

**Pull requests are welcome** if they align with the project’s didactic goals.

---

## 📜 **License**
This project is **free to use** for educational purposes under the **42 School open-source policy**.
For commercial use, contact the original author.
