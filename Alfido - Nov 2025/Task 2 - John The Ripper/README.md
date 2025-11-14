## John the Ripper Enhanced Cracking Workflow

# Note: The password used for 'secret.zip' must be a simple, weak one (e.g., 'password123') for these short demonstrations to succeed quickly.
# Ensure you have the 'zip2john' and 'john' utilities installed and a wordlist like 'rockyou.txt' available for the dictionary attack demonstration.

### 1. Creating the Target File
echo "Sensitive data for internship project." > confidential.txt

### 2. Creating a Password-Protected ZIP File
# The user will be prompted to enter the password (e.g., "weakpass")
zip -e secret.zip confidential.txt
rm confidential.txt # Clean up the original file

### 3. Extracting the Hash for Cracking
# Converts the ZIP file's encrypted metadata into a JtR-compatible hash format
zip2john secret.zip > zip_hash.txt

---

### 4. Basic Cracking Attempt (Internal Dictionary/Rules)
# JtR attempts its fast, built-in wordlist and rule-based attacks
echo "--- Running Basic Crack (Internal Dictionary/Rules) ---"
john zip_hash.txt
# If the password is weak, it often cracks here.

### 5. Dictionary Attack (Using an External Wordlist)
# Demonstrates using a specific, large wordlist (like rockyou.txt, common in cybersec environments)
# Replace '/path/to/wordlist.txt' with the actual path (e.g., /usr/share/wordlists/rockyou.txt)
echo "--- Running Dictionary Attack (External Wordlist) ---"
john --wordlist=/path/to/wordlist.txt zip_hash.txt

### 6. Incremental/Brute-Force Attack
# This is slow but guaranteed to find the password eventually for a given character set.
# Use the 'All' mode for maximum coverage (slowest) or 'Digits' for demonstration on simple numeric passwords.
echo "--- Running Brute-Force Attack (Incremental) ---"
john --incremental=All zip_hash.txt

---

### 7. Managing Cracking Sessions
# Check the status of a currently running session without interrupting it
echo "--- Checking Session Status ---"
john --status zip_hash.txt

# Stop a running session (e.g., after 5 minutes of brute-forcing) and save the progress
# (Wait for the cracking process from step 6 to start, then press Ctrl+C to stop/save it)
# Then, resume the saved session later
echo "--- Resuming Previous Session ---"
john --restore zip_hash.txt

### 8. Displaying All Cracked Passwords
# Shows all passwords recovered from the 'zip_hash.txt' file, regardless of which cracking mode found them
echo "--- Final Cracked Password Display ---"
john --show zip_hash.txt

### 9. Clean Up
# Removing the generated files to clean the environment
rm zip_hash.txt
rm secret.zip
# Remove John the Ripper's session and pot files for a clean slate (optional)
# rm ~/.john/john.pot
# rm ~/.john/john.rec