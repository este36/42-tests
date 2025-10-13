import { execFileSync } from 'node:child_process';

const ANSI_GREEN = "\x1b[32m";
const ANSI_RED = "\x1b[31m";
const ANSI_RESET = "\x1b[0m";

function doTest(n)
{
	const c_stdout = execFileSync('./test_ft_printf',['--c', n.toString()]).toString();
	const ft_stdout = execFileSync('./test_ft_printf',['--ft', n.toString()]).toString();
	process.stdout.write(`Test ${n.toString()}:`);
	if (ft_stdout !== c_stdout)
	{
		const args = execFileSync('./test_ft_printf',['--print-args', n.toString()]).toString();
		process.stdout.write(`${ANSI_RED + " Error!" + ANSI_RESET}\n`);
		console.log(`Arguments:\t${args}`);
		console.log(`C result:\t\"${c_stdout}\"`);
		console.log(`FT result:\t\"${ft_stdout}\"`);
		return (false);
	} else {
		process.stdout.write(ANSI_GREEN + " OK\n" + ANSI_RESET);
	}
	return (true);
}

for (let i = 1; i < 10; i++)
{
	doTest(i);
	// if (!doTest(i)) process.exit(1);
}

process.exit(0);
