module Impl = (T: {type t;}) => {
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.val] external data: T.t = "platform";

  module OS = {
    type t;
    [@bs.module "benchmark"] [@bs.scope ("Benchmark", "platform")] [@bs.val] external data: t = "os";
    [@bs.get] external getArchitecture: t => Js.Nullable.t(string) = "architecture";
    [@bs.get] external getFamily: t => Js.Nullable.t(string) = "family";
    [@bs.get] external getVersion: t => Js.Nullable.t(string) = "version";
    [@bs.send.pipe: t] external toString: string = "toString";
  };

  [@bs.get] external getDescription: T.t => Js.Nullable.t(string) = "description";
  [@bs.get] external getLayout: T.t => Js.Nullable.t(string) = "layout";
  [@bs.get] external getProduct: T.t => Js.Nullable.t(string) = "product";
  [@bs.get] external getName: T.t => Js.Nullable.t(string) = "name";
  [@bs.get] external getManufacturer: T.t => Js.Nullable.t(string) = "manufacturer";
  [@bs.get] external getOS: T.t => Js.Nullable.t(OS.t) = "os";
  [@bs.get] external getPrerelease: T.t => Js.Nullable.t(string) = "prerelease";
  [@bs.get] external getVersion: T.t => Js.Nullable.t(string) = "version";
  [@bs.send.pipe: T.t] external toString: string = "toString";
};