/**
 * [ Platform ]
 *
 * Contains functions for getting information about the host environment,
 * including the browser/runtime, operating system, physical device model,
 * device manufacturer, etc.
 * 
 * All of the values are initialized when the code is first loaded.
 */
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

  /** A short string describing the host operating system and runtime platform. */
  let description: option(string) = Internal.(getDescription(data) -> nullToOption);
  /** The host platform's JS interpreter engine. E.g. "WebKit", "V8", "SpiderMonkey". */
  let layout: option(string) = Internal.(getLayout(data) -> nullToOption);
  /** The host device name. E.g. "iPad", "Android Galaxy S3". */
  let product: option(string) = Internal.(getProduct(data) -> nullToOption);
  /** The name of the host platfrom or browser. E.g. "Safari", "Node", "Firefox". */
  let name: option(string) = Internal.(getName(data) -> nullToOption);
  /** The name of the device manufacturer. E.g. "HP", "Apple", "Microsoft". */
  let manufacturer: option(string) = Internal.(getManufacturer(data) -> nullToOption);
  /** The name of the host operating system. E.g. "Ubuntu 18.04". */
  let os: option(OS.t) = Internal.(getOS(data) -> nullToOption);
  /** The aplph/beta release indicator. */
  let prerelease: option(string) = Internal.(getPrerelease(data) -> nullToOption);
  /** The version of the host operating system. */
  let version: option(string) = Internal.(getVersion(data) -> nullToOption);
  /** Returns the [ description ] property (string) or an empty string if the description is not available. */
  let toString: unit => string = () => Internal.(toString(data));

};

include Impl({
  include Types;
  type t = platform;
});