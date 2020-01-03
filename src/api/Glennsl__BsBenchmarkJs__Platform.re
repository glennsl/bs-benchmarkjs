module Impl = (T: {type t;}) => {
  module Internal = {
    include Glennsl__BsBenchmarkJs__FFI.Platform.Impl({
      type t = T.t;
    });
    let nullToOption = Js.Nullable.toOption;
  }
  module OS = {
    type t = Internal.OS.t;
    let architecture: option(string) = Internal.(OS.getArchitecture(OS.data) -> nullToOption)
    let family: option(string) = Internal.(OS.getFamily(OS.data) -> nullToOption)
    let version: option(string) = Internal.(OS.getVersion(OS.data) -> nullToOption)
    let toString: string = Internal.(OS.toString(OS.data))
  };
  let description: option(string) = Internal.(getDescription(data) -> nullToOption);
  let layout: option(string) = Internal.(getLayout(data) -> nullToOption);
  let product: option(string) = Internal.(getProduct(data) -> nullToOption);
  let name: option(string) = Internal.(getName(data) -> nullToOption);
  let manufacturer: option(string) = Internal.(getManufacturer(data) -> nullToOption);
  let os: option(OS.t) = Internal.(getOS(data) -> nullToOption);
  let prerelease: option(string) = Internal.(getPrerelease(data) -> nullToOption);
  let version: option(string) = Internal.(getVersion(data) -> nullToOption);
  let toString: unit => string = () => Internal.(toString(data));
};