
(cl:in-package :asdf)

(defsystem "ISLH_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
  ))