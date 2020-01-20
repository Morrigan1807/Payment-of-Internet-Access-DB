#pragma once

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для ShiftOperators
	/// </summary>
	public ref class ShiftOperators : public System::Windows::Forms::Form
	{
	public:
		ShiftOperators(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT DISTINCT Shift_number FROM Shift_operators JOIN Shifts ON Shift_operators.ID_shift = Shifts.ID_shift";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			while (dr->Read())
			{
				this->O_shift->Items->Add(dr[0]);
			}
			connect->Close();
			dr->Close();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ShiftOperators()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Reload_list;
	protected:
	private: System::Windows::Forms::Button^  exit;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  O_shift;
	public: Form^ general;
	private: System::Windows::Forms::DataGridView^  Operators_list;
	public:

	private: System::Windows::Forms::Button^  save;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Drawing::Printing::PrintDocument^  printDocument1;

	public:
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ShiftOperators::typeid));
			this->Reload_list = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->O_shift = (gcnew System::Windows::Forms::ComboBox());
			this->Operators_list = (gcnew System::Windows::Forms::DataGridView());
			this->save = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Operators_list))->BeginInit();
			this->SuspendLayout();
			// 
			// Reload_list
			// 
			this->Reload_list->Location = System::Drawing::Point(22, 445);
			this->Reload_list->Name = L"Reload_list";
			this->Reload_list->Size = System::Drawing::Size(110, 23);
			this->Reload_list->TabIndex = 0;
			this->Reload_list->Text = L"Обновить список";
			this->Reload_list->UseVisualStyleBackColor = true;
			this->Reload_list->Click += gcnew System::EventHandler(this, &ShiftOperators::Reload_list_Click);
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(280, 445);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 1;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &ShiftOperators::exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(377, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Смена:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(64, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(145, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Сотрудники данной смены:";
			// 
			// O_shift
			// 
			this->O_shift->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->O_shift->Location = System::Drawing::Point(340, 33);
			this->O_shift->Name = L"O_shift";
			this->O_shift->Size = System::Drawing::Size(121, 21);
			this->O_shift->TabIndex = 6;
			// 
			// Operators_list
			// 
			this->Operators_list->AllowUserToAddRows = false;
			this->Operators_list->AllowUserToDeleteRows = false;
			this->Operators_list->AllowUserToResizeColumns = false;
			this->Operators_list->AllowUserToResizeRows = false;
			this->Operators_list->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Operators_list->BackgroundColor = System::Drawing::Color::White;
			this->Operators_list->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Operators_list->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->Operators_list->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Operators_list->ColumnHeadersVisible = false;
			this->Operators_list->Enabled = false;
			this->Operators_list->Location = System::Drawing::Point(67, 101);
			this->Operators_list->Name = L"Operators_list";
			this->Operators_list->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->Operators_list->RowHeadersVisible = false;
			this->Operators_list->Size = System::Drawing::Size(715, 295);
			this->Operators_list->TabIndex = 7;
			// 
			// save
			// 
			this->save->Location = System::Drawing::Point(164, 445);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(75, 23);
			this->save->TabIndex = 8;
			this->save->Text = L"Сохранить список";
			this->save->UseVisualStyleBackColor = true;
			this->save->Click += gcnew System::EventHandler(this, &ShiftOperators::save_Click);
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &ShiftOperators::printDocument1_PrintPage);
			// 
			// ShiftOperators
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(845, 496);
			this->Controls->Add(this->save);
			this->Controls->Add(this->Operators_list);
			this->Controls->Add(this->O_shift);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Reload_list);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ShiftOperators";
			this->Text = L"Операторы смены";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ShiftOperators::ShiftOperators_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Operators_list))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		general->Enabled = true;
		this->Close();
	}
private: System::Void ShiftOperators_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
private: System::Void Reload_list_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (O_shift->Text != "")
	{
		Operators_list->Rows->Clear();
		Operators_list->ColumnCount = 5;	
		Operators_list->Rows->Add("","Операторы " + O_shift->Text->ToString() + " смены:");
		Operators_list->Rows->Add("","ФИО оператора:", "Занимаемая должность:", "Домашний адрес:", "Мобильный телефон:");
		String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
		SqlConnection^ connect = gcnew SqlConnection(db);
		SqlCommand^ command = connect->CreateCommand();
		int i = 1;
		command->CommandText = "SELECT DISTINCT Full_name, Position, Adress, Telephone FROM Shift_operators JOIN Operators ON Shift_operators.Operator_number = Operators.Operator_number "+
			"JOIN Shifts ON Shift_operators.ID_shift = Shifts.ID_shift WHERE Shift_number = \'" + O_shift->Text->ToString() + "\'";
		command->Connection = connect;
		SqlDataReader^ dr;
		connect->Open();
		dr = command->ExecuteReader();
		while (dr->Read())
		{
			Operators_list->Rows->Add(Convert::ToString(i),dr[0]->ToString(), dr[1]->ToString(), dr[2]->ToString(), dr[3]->ToString());
			i++;
		}
		connect->Close();
		dr->Close();
	}
	else
	{
		MessageBox::Show("Ошибка! Необходимо выбрать смену.");
	}
}
private: System::Void save_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Operators_list->ClearSelection();
	printDocument1->PrinterSettings->PrinterName = "Adobe PDF";
	printDocument1->Print();
}
private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) 
{
	Bitmap^ bmp = gcnew Bitmap(Operators_list->Size.Width, Operators_list->Size.Height);
	Operators_list->DrawToBitmap(bmp, Operators_list->Bounds);
	e->Graphics->DrawImage(bmp, 80, 1);
}
};
}
