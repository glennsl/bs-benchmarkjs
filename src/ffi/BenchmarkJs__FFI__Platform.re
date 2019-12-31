module Impl = (T: {type t;}) => {
  // global object
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.val] external data: T.t = "platform";
  // instance properties
  [@bs.get] external getDescription: T.t => string = "description";
  [@bs.get] external getLayout: T.t => string = "layout";
  [@bs.get] external getProduct: T.t => string = "product";
  [@bs.get] external getName: T.t => string = "name";
  [@bs.get] external getManufacturer: T.t => string = "manufacturer";
  [@bs.get] external getOS: T.t => string = "os";
  [@bs.get] external getPrerelease: T.t => string = "prerelease";
  [@bs.get] external getVersion: T.t => string = "version";
  // instance methods
  [@bs.send.pipe: T.t] external toString: string = "toString";
};