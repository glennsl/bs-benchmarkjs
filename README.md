
# bs-benchmarkjs

`bs-benchmarkjs` provides BuckleScript external type bindings to [Benchmark.js](https://benchmarkjs.com/), an excellent JavaScript performance benchmark library. This package attempts to provide a faithful representation of the original JavaScript API, but with a small number of opinionated restrictions & additions to make it friendlier to consume from ReasonML or OCaml.

While much of the API is documented in our source code via standard 'doc-comments', it may be helpful to refer to the [official Benchmark.js API docs](https://benchmarkjs.com/docs). (Please note that these docs may not be 100% updated with the library version in few cases.)

## Installation

You can install `bs-benchmarkjs` using either NPM or Yarn. With one of those package managers installed, navigate to the root directory of your project (where the `package.json` file is located), and run the following command associated with your package manager:

### NPM

```bash
npm install --save bs-benchmarkjs
```

### Yarn

```bash
yarn add bs-benchmarkjs
```

## Usage

See [examples](https://github.com/glennsl/bs-benchmarkjs/tree/master/examples):

```reason
let () = {

  open Glennsl__BsBenchmarkJs;

  Suite.(

    make("String To Uppercase")
    |> onStart((. _) => Js.log("-- Running Benchmarks --\r\n"))
    |> onError((. evt) => Event.getType(evt) |> Js.log)
    |> onComplete((. _) => Js.log("-- Done --\r\n"))

    |> add("Map Char Function", (. ) => {
      let result = ref("");
      result := result^ ++ "Hello Benchmark.js!"
      result := result^ |> String.map((character) => Char.uppercase_ascii(character));
    })

    |> add("Use String Function", (. ) => {
      let result = ref("");
      result := result^ ++ "Hello Benchmark.js!"
      result := result^ |> String.uppercase_ascii;
    })

    |> run
    |> toList
    |> List.iter( benchmark =>
        Benchmark.toString(benchmark)
        |> Js.log
      )

  );

};
```

## Notes on Performance Testing

When running performance benchmarks on plain Javascript code, your code is tested precisely as it is written in the source code. However, when compiling from OCaml or Reason, this is not the case. The underlying JS representation may vary for several reasons. Here are just a few:

  1. Different BuckleScript versions will sometimes generate *very* different JS code in the output file.
  2. BuckleScript will sometimes perform optimizations on the JS output. This includes function-inlining, tail-call elimination, closure elimination, and even eliminating entire blocks of code (e.g. with unreachable code paths, or when executing the code will not affect the program in any observable way).
  3. Combinations of different expressions are not cleanly expressed in JS, so the final representation may depend on surrounding context.
  4. BuckleScript may introduce additional overhead with helper functions for things like currying or null-checking. In some cases, these function calls can be avoided, but not all of them.

With that in mind, users of this library should take benchmark results with a grain of salt.

In general, writing smaller test cases may yield more variable results, since small differences in compilation strategies will have greater influence on the code. Likewise, larger test cases will likely yield more normalized results. The obvious downside is that larger, more complicated test cases make it harder to measure specific patterns in isolation.

Therefore, it may be more useful to write test cases which perform some *concrete, realistic* task that you care about. That way, any variance in the generated code will more accurately reflect what you can expect to see in real-world applications. This kind of insight is likely to be more beneficial than trivial "micro-benchmarks" in practice.

Otherwise, for micro-benchmarks, it may be helpful to manually inspect the generated code, to make sure you understand what you are really measuring.

## Contributing

All suggestions and contributions are welcome. If you find a bug or would like to see some improvements, please file an issue on GitHub to discuss. Also, we welcome any pull requests, and we will happily merge them after review, as long as they conform to the main goals of this project.
