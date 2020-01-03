
# bs-benchmarkjs

BuckleScript external type bindings to [Benchmark.js](https://benchmarkjs.com/), an excellent JavaScript performance benchmark library.

## Usage

See [examples](https://github.com/glennsl/bs-benchmarkjs/tree/master/examples):

```ocaml
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
