using System;
using System.Collections.Generic;

class Program
{
	static void Main()
	{
		Dictionary<string, int> dictionary = new Dictionary<string, int>();
		dictionary.Add("apple", 100);
		dictionary.Add("windows", 500);
		if (dictionary.ContainsKey("apple"))
			Console.WriteLine(dictionary["apple"]);
		if (!dictionary.ContainsKey("acorn"))
			Console.WriteLine(false);
	}
}