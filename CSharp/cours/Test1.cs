// Exemple 1:
int i = 5; 
System.Console.WriteLine(i.ToString());

// Exemple 2:
Stack stack = new Stack();
stack.Push(i); // boxing
int j = (int)stack.Pop(); // unboxing
