<?php

namespace orm\exception;

class ParseClassDescErrorException extends \Exception {

	public function __construct ($msg) {
		$this->code = SystemErrcode::ParseClassDescError;
		$this->message = $msg;
	}
}
?>