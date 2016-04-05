Pod::Spec.new do |s|
s.name             = "DroiPushSDK"
s.version          = "0.0.2"
s.summary          = "DroiPushSDK iOS 卓易推送"
s.description      = "DroiPushSDK iOS 卓易推送，使得开发者可以即时地向其应用程序的用户推送通知或者消息，与用户
保持互动，从而有效地提高留存率，提升用户体验"
It is a marquee view used on iOS, which implement by Objective-C.
DESC
s.homepage         = "https://github.com/DroiBaaS"
# s.screenshots      = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
s.license          = 'MIT'
s.author           = { "DoriBaaS" => "droiinfo@droi.com" }
s.source           = { :git => "https://github.com/DroiBaaS/DroiPushSDK.git", :tag => s.version.to_s }
# s.social_media_url = 'https://twitter.com/NAME'

s.platform     = :ios, '7.0'
# s.ios.deployment_target = '6.0'
# s.osx.deployment_target = '10.7'
s.requires_arc = true

s.source_files = 'DroiPush/*.h'
s.vendored_libraries = 'DroiPush/*.a'
#s.resources = '/*'

# s.ios.exclude_files = 'Classes/osx'
# s.osx.exclude_files = 'Classes/ios'
# s.public_header_files = 'Classes/**/*.h'
s.frameworks = 'Foundation', 'UIKit'

end