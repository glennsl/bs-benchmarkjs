module Impl = (T: {type t;}) => {
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] external data: T.t = "support";
  // instance properties
  [@bs.get] external getBrowser: T.t => bool = "browser";
  [@bs.get] external getDecompilation: T.t => bool = "decompilation";
  [@bs.get] external getTimeout: T.t => bool = "timeout";
};