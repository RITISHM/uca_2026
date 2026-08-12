function* CalculatorGenerator(initialValue) {
  let value = initialValue;

  console.log(value);

  while (true) {
    let x = yield;

    if (typeof x.operation != "string" || typeof x.value != "number") {
      console.log("Invalid input");
    } else if (x.operation == "add") {
      value += x.value;
      console.log(value);
    } else if (x.operation == "multiply") {
      value *= x.value;
      console.log(value);
    } else if (x.operation == "divide") {
      if (x.value == 0) {
        console.log("Invalid input");
      } else {
        value /= x.value;
        console.log(value);
      }
    } else if (x.operation == "subtract") {
      value -= x.value;
      console.log(value);
    } else {
      console.log("Invalid input");
    }
  }
}

// Sample Input and Output

const calc = CalculatorGenerator(50);

calc.next(); // 50
calc.next({ operation: "add", value: 30 }); // 80
calc.next({ operation: "multiply", value: "2" }); // Invalid input
calc.next({ operation: "add", value: "30" }); // Invalid input
calc.next({ operation: "multiply", value: 0 }); // 0
