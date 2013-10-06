using System;
using System.Collections.Generic;

namespace DictionaryForeach
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Dictionary<string, int> dictionary = new Dictionary<string, int>();
			dictionary.Add("apple", 100);
			dictionary.Add("windows", 500);
			foreach (var pair in dictionary)
				Console.WriteLine("{0}, {1}", pair.Key, pair.Value);
		}
	}
}
