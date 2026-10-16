# Console Banking System

A menu-driven banking system written in C. It demonstrates basic account management, deposits and withdrawals, balance checks, loan handling, and simple file-based data persistence.

> **Note:** This is an educational project, not production banking software. Account and administrator passwords are stored in plain text, and the application does not provide real authentication or financial safeguards. Do not use it to manage real money or sensitive information.

## Features

- Create and delete accounts
- Deposit and withdraw funds
- Check balances and change an account password
- Request and repay loans, with a maximum loan balance of 100,000
- Administrator menu for viewing accounts, with an administrator-password change option
- Save account data between runs in `accounts.txt`

The application supports up to 100 accounts. Account names must not contain spaces.

## Requirements

- A C compiler, such as GCC
- A Windows environment or compatible toolchain: the program uses `<conio.h>`, `getch()`, and `system("cls")`

## Build and run

From the repository directory, compile with GCC:

```sh
gcc BankingFinal.c -o BankingSystem.exe
```

Then run the program:

```sh
BankingSystem.exe
```

The administrator login uses the default password `ADM`. Although the administrator menu offers a password-change option, the login currently continues to check against `ADM`. The program creates or updates `accounts.txt` in its current working directory; keep that file if you want to retain saved account data.

## Platform note

The source currently targets Windows-style console behavior. The repository includes a note for macOS/Linux users in `Error in Mac or Linux`, but making the suggested substitutions alone may not be sufficient to make the program portable.
