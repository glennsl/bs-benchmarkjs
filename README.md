
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

## Contributing

All suggestions and contributions are welcome. If you find a bug or would like to see some improvements, please file an issue on GitHub to discuss. Also, we welcome any pull requests, and we will happily merge them after review, as long as they conform to the main goals of this project.
