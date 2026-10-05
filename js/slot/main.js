/* NOTE: PACKAGES USED
 *
 * prompt-sync
 */

/* TODO: STEPS
 *
 * deposit some money
 * determine the number of lines to bet on
 * collect a bet amount
 * spin the slot machine
 * check if the user won
 * give the user their winnings
 * play again
 */

const prompt = require("prompt-sync")();

const ROWS = 3;
const COLS = 3;

/* Variables 
 * Let: Mutable
 * Const: Immutable
 */

const SYMBOLS_COUNT = {
	"A": 2,
	"B": 4,
	"C": 6,
	"D": 8,
}

const SYMBOLS_VALUE = {
	"A": 5,
	"B": 4,
	"C": 3,
	"D": 2,
}

function deposit() {
	while (true) {
		// prompt returns string
		const deposit_amount = prompt("  $ Enter a deposit amount: $");
		const num_deposit_amount = parseFloat(deposit_amount);

		if (isNaN(num_deposit_amount) || num_deposit_amount <= 0) {
			console.log("Invalid input! Try Again!");
		}
		else {
			return num_deposit_amount;
		}
	}
}

function get_num_of_lines() {
	while (true) {
		const lines = prompt("  $ Enter the number of lines to bet on (1-3): ");
		const num_lines = parseFloat(lines);

		if (isNaN(num_lines) || num_lines <= 0 || num_lines > 3) {
			console.log("Invalid input! Try Again!");
		}
		else {
			return num_lines;
		}
	}
}

function bet(balance, lines) {
	while (true) {
		const bet_amt = prompt("  $ Enter the total bet: ");
		const num_bet_amt = parseFloat(bet_amt);

		if (isNaN(num_bet_amt) || num_bet_amt <= 0) {
			console.log("Invalid input! Try Again!");
		}
		// bet is placed per line
		else if (num_bet_amt * lines > balance) {
			console.log("Not enough funds! Try Again!");
		}
		else {
			return num_bet_amt;
		}
	}
}

function spin() {

	const symbols_arr = [];
	for (const [symbol, count] of Object.entries(SYMBOLS_COUNT)) {
		for (let i = 0; i < count; i++) {
			symbols_arr.push(symbol);
		}
	}

	// nested arrays
	// my eyes exploded after seeing this
	// im a C dev btw
	const slots = [];

	for (let i = 0; i < COLS; i++) {
		slots.push([]);
		// shallow copy
		const slot_symbols = [...symbols_arr];
		for (let j = 0; j < ROWS; j++) {
			const random_index = Math.floor(Math.random() * slot_symbols.length);
			const selected_symbol = slot_symbols[random_index];
			slots[i].push(selected_symbol);
			// removes one element from the index
			slot_symbols.splice(random_index ,1)
		}
	}

	return slots;
}

function transpose(slots) {
	const rows = [];

	for (let i = 0; i < ROWS; i++){
		rows.push([]);
		for (let j = 0; j < COLS; j++){
			rows[i].push(slots[j][i]);
		}
	}

	return rows;
}

function print_rows(rows) {

	let row_string = "\n  ╭───────────╮\n";
	for (const row of rows) {
		for (const [i, symbol] of row.entries()) {
			if (i == 0) {
				row_string += "  │ ";
			}
			row_string += symbol;
			if (i != (row.length - 1)) {
				row_string += " │ ";
			} else {
				row_string += " │";
			}
		}
		row_string += "\n";
	}
	row_string += "  ╰───────────╯\n"

	console.log(row_string);
}

function get_winnings(rows, bet, lines) {
	let winnings = 0;

	for (let row = 0; row < lines; row++){
		const symbols = rows[row];
		let won = true;

		for (const symbol of symbols) {
			if (symbol != symbols[0]) {
				won = false;
				break;
			}
		}

		if (won) {
			winnings += bet * SYMBOLS_VALUE[symbols[0]];
		}
	}
	return winnings;
}

function main() {

	console.clear();
	console.log("\n")
	let deposit_amount = deposit();
	const num_lines = get_num_of_lines();
	let bet_amount = bet(deposit_amount, num_lines);
	const slots = (spin());
	const rows = transpose(slots);
	const winnings = get_winnings(rows, bet_amount, num_lines);

	print_rows(rows);
	console.log(" >> You Won $" + winnings);

	return 0;
}

main();

