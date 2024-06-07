# Cash-Flow-Minimizer
This project implements a simple cash flow minimization algorithm to optimize the payments among a group of participants. The goal is to minimize the number of transactions required to settle debts between participants based on their pairwise transactions.

Features:
Input Handling: Accepts the number of participants and their names.
Transaction Input: Collects the amounts owed between each pair of participants.
Cash Flow Optimization: Uses an algorithm to determine the minimum number of transactions needed to settle all debts.
Output: Prints out the optimized transactions that minimize the cash flow among the participants.

How It Works
Participant Input: The user is prompted to enter the number of participants (up to a maximum of 100), and then to enter the names of each participant.
Transaction Input: The user is asked to input the amount of money each participant owes to every other participant.
Net Amount Calculation: The program calculates the net amount to be paid or received by each participant.
Cash Flow Optimization: The program identifies the maximum creditor and debtor, and settles the debts in a way that minimizes the number of transactions.
Output Transactions: The program prints out the optimized transactions required to settle all debts.
