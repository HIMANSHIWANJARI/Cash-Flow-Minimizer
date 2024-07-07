# Cash-Flow-Minimizer
Overview :

This system is designed to minimize the number of transactions among multiple banks. The objective is to efficiently settle all debts and credits among the banks, thereby reducing the total number of transactions required.


How to Use :

When you execute the program, it guides you through the process:
1. Enter the number of banks.
2. Enter the names of the banks.
3. Enter the number of transactions.
4. For each transaction, provide the debtor bank, creditor bank, and amount separated by spaces.
5. The program then processes the transactions and prints out the minimized number of transactions required to settle all debts.

![Screenshot (133)](https://github.com/HIMANSHIWANJARI/Cash-Flow-Minimizer/assets/126982834/e5c4bf2e-038f-40a3-add1-7bdff5770ec5)

Mathematical Basis: 

To minimize transactions, we calculate the net amount for each bank using the formula:
net amount = (Sum of all credits) − (Sum of all debits)

This results in a net balance list indicating how much each bank needs to pay or receive.
1. Identify the bank with the minimum net amount (maximum debtor) and the bank with the maximum net amount (maximum creditor) that share a common payment mode.
2. Determine the minimum of the absolute values of the debtor and creditor amounts, say x
3. Perform a transaction where the debtor pays x to the creditor.
4. Update the net amounts accordingly and remove any settled banks (those with net amount zero) from further consideration.
5. Repeat the process until all debts are settled.

Thank you for using the Cash Flow Minimizer!
